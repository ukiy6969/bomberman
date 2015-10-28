#include "inet.h"                         /* 前の inet.h を include */
#define BUFSIZE 1024

char reverse(char s) {
  if (islower(s)){
    return (char)toupper((int)s);
  }
  return (char)tolower((int)s);
}

void reverse_str(char *src, char *dist, int n) {
  int i;
  for (i = 0; i < n; i++) {
    dist[i] = reverse(src[i]);
  }
}

int service(int fd)                       /* サーバの仕事，終わりならば0を返す */
{                                         /* fd は通信に用いるファイル記述子 */
  char b[BUFSIZE];                        /* 一時的なバッファ */
  char ret[BUFSIZE];
  int n;

  if ( (n = read(fd, b, BUFSIZE)) <= 0 )  /* fd から読み込む */
    return 0;                             /* 文字数が0以下なら終わり */
  reverse_str(b, ret, BUFSIZE);
  printf("fd = %d, n = %d, b = \"%s\"\n", fd, n, b);
  write(fd, ret, BUFSIZ);
                                          /* fd，長さ，受信文字列を出力 */
  return n;
}

void update_min_max(int fd, int *min, int *max){
  if ((*min) > fd) {
    (*min) = fd;
  }
  if ((*max) < fd){
    (*max) = fd;
  }
}

void search_min_max (fd_set fd, int *min, int *max){
  int i;
  for(i=0; i < FD_SETSIZE; i++){
    if (FD_ISSET(i, &fd)){
      if (*min > i) {
        *min = i;
      }
      if (*max < i) {
        *max = i;
      }
    }
  }
  printf("searched min: %d max %d\n", *min, *max);
}

void error(char *s)                       /* エラー処理 */
{
  perror(s);                              /* メッセージの出力 */
  exit(1);                                /* 1を返しておしまい */
}

int main(int argc, char **argv)
{
  int sockfd, newfd;
  struct sockaddr_in sin, cli;
  int clilen;
  fd_set allfds, fds;                        /* ビットマスク */
  int fd, fd_min, fd_max;

  game g;
  create_game(&g);
  print_b(&g.b);

  if ( (sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0 ) /* ソケット */
    error("cannot create socket");
  bzero((char *)&sin, sizeof(sin));          /* sin に 0 をつめる */
  sin.sin_family = PF_INET;                  /* Internet ドメイン */
  sin.sin_addr.s_addr = htonl(INADDR_ANY);   /* アドレスは何でもOK */
  sin.sin_port = htons(SERVER_PORT);         /* ポートは SERVER_PORT */
  if ( bind(sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0 )
    error("cannot bind");
  if ( listen(sockfd, 5) < 0 )
    error("cannot listen");
  FD_ZERO(&allfds);                          /* すべてゼロにクリア */
  FD_SET(sockfd, &allfds);                   /* sockfdのところに1を立てる */
  fd_min = sockfd; fd_max = sockfd;
  search_min_max(allfds, &fd_min, &fd_max);
  printf("min %d max %d\n", fd_min, fd_max);
  while ( 1 ) {
    fds = allfds;                            /* fdsはselectにより変化するかも */
    if ( select(FD_SETSIZE, &fds, NULL, NULL, NULL) < 0 )
      error("cannot select");
    for ( fd = 0; fd < FD_SETSIZE; fd++ )    /* ファイル記述子を順に調査 */
      if ( FD_ISSET(fd, &fds) ) {            /* ビットが立っていた */
        update_min_max(fd, &fd_min, &fd_max);
        if ( fd == sockfd ) {                /* 入力受付用ファイル記述子の場合 */
          clilen = sizeof(cli);              /* 接続を受け入れる準備 */
          if ( (newfd = accept(sockfd, (struct sockaddr *)&cli, &clilen)) < 0 )
            error("cannot accept");
          update_min_max(newfd, &fd_min, &fd_max);
          printf("Accetpted new connection: fd = %d\n", newfd);
          FD_SET(newfd, &allfds);            /* selectによる調査対象に加える */
        } else if ( service(fd) == 0 ) {     /* クライアントからの要求処理 */
          printf("Closed connection: fd = %d\n", fd);
          if ( shutdown(fd, SHUT_RDWR) < 0 ) /* これ以上の送受信を禁止 */
            error("cannot shutdown");
          FD_CLR(fd, &allfds);               /* selectによる調査対象から外す */
          close(fd);
          search_min_max(allfds, &fd_min, &fd_max);
        }
      }
  }
  return 0;
}
