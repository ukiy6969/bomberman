#include "inet.h"                         /* 前の inet.h を include */
#define BUFSIZE 1024

int battle[2];
game g;

int service(int fd, game* g)                       /* サーバの仕事，終わりならば0を返す */
{                                         /* fd は通信に用いるファイル記述子 */
  char b[BUFSIZE];                        /* 一時的なバッファ */
  int n;
  int input;
  int c;

  if ( (n = read(fd, b, BUFSIZE)) <= 0 )  /* fd から読み込む */
    return 1;
  if ( 31 > atoi(b) || 256 < atoi(b) ){
    return 1;
  }
  printf("\nfd = %d, n = %d, b = \"%d\"\n", fd, n, atoi(b));
  if ( battle[0] == fd && battle[1] != 0) {
    write(battle[1], b, BUFSIZ);
    c = atoi(b);
    if ( (c == KEY_UP) || (c == KEY_DOWN)
          || (c == KEY_LEFT) || (c == KEY_RIGHT) ) {
      system("/bin/stty cooked");
      move(g,0, c);
      print_field(g);
    }
    if ( (c == BOMB) && !g->m_is_bomb) {
      bomb_args bargs = { 2, g };
      if ( g->position == 0) {
        if (set_bomb_m(g) ){
        }
      }
      print_field(g);
    }
  } else if ( battle[1] == fd &&  battle[0] != 0) {
    write(battle[0], b, BUFSIZ);
    c = atoi(b);
    if ( (c == KEY_UP) || (c == KEY_DOWN)
          || (c == KEY_LEFT) || (c == KEY_RIGHT) ) {
      move(g,1, c);
      print_field(g);
    }
    if ( (c == BOMB) && !g->m_is_bomb) {
      bomb_args bargs = { 2, g };
      if (set_bomb_a(g) ){
      }
      print_field(g);
    }
  }
  system("/bin/stty cooked");
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

  create_game(&g);

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
          if (battle[0] == 0 ){
            battle[0] = newfd;
            write(newfd, "0", 6);
          } else if(battle[0] != 0) {
            battle[1] = newfd;
            write(newfd, "1", 6);
          } else if (battle[1] != 0) {
          }
          update_min_max(newfd, &fd_min, &fd_max);
          printf("Accetpted new connection: fd = %d\n", newfd);
          FD_SET(newfd, &allfds);            /* selectによる調査対象に加える */
        } else if ( service(fd, &g) == 0 ) {     /* クライアントからの要求処理 */
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
