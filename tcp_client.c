#include "inet.h"                /* サーバと同じ inet.h を共用 */
#define BUFSIZE 1024

int position = 0;

void error(char *s)              /* エラー処理 (サーバと同じ) */
{
  perror(s);
  exit(1);
}
void mclient(int fd, game *g) {
  char b[BUFSIZE];
  int n;
  char c;
  fd_set allfds, fds;
  FD_ZERO(&allfds);
  FD_SET(0, &allfds);
  FD_SET(fd, &allfds);
  print_field(g);
  while ( 1 ) {
    fds = allfds;
    system ("/bin/stty raw");
    if ( select(FD_SETSIZE, &fds, NULL, NULL, NULL) < 0 ) {
      error("cannot select");
    }
    if ( FD_ISSET(0, &fds) ) {
      c = getchar();
      system ("/bin/stty cooked");
      printf("%s\n", b);
      if ( c== '.') {
        return;
      }
      if ( (c == KEY_UP) || (c == KEY_DOWN)
            || (c == KEY_LEFT) || (c == KEY_RIGHT) ) {
        move(g,position, c);
        system("clear");
        print_field(g);
        write(fd, b, BUFSIZ);
      }
      if ( (c == BOMB) ) {
        set_bomb_m(g);
        print_field(g);
      }
    }
    if ( FD_ISSET(fd, &fds) ) {
      system ("/bin/stty cooked");
      n = read(fd, b, BUFSIZ);
      c = atoi(b);
      if ( (c == KEY_UP) || (c == KEY_DOWN)
            || (c == KEY_LEFT) || (c == KEY_RIGHT) ) {
        if ( move(g,position^1, c)){
          return;
        }
        system("clear");
        print_field(g);
      }
    }
  }
}

void client(int fd, game *g) {
  char b[BUFSIZE];
  int n;
  char c;
  /* use system call to make terminal send all keystrokes directly to stdin */
  if(read(fd, b, BUFSIZ) > 0) {
    n = atoi(b);
    printf("%d\n", n);
    position = n;
    mclient(fd, g);
  }

}


int main(int argc, char **argv)
{
  int sockfd;
  struct sockaddr_in sin;
  game g;
  create_game(&g);
  show_boningen(&g);

  if ( (sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0 ) /* socket */
    error("cannot create socket");
  bzero((char *)&sin, sizeof(sin));          /* sin に 0 をつめる */
  sin.sin_family = PF_INET;                  /* Internet ドメイン */
  sin.sin_addr.s_addr = inet_addr(SERVER_ADDR); /* アドレスはサーバ */
  sin.sin_port = htons(SERVER_PORT);         /* ポートは SERVER_PORT */
  if ( connect(sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0 )
    error("cannot connect");
  client(sockfd, &g);                            /* クライアントの仕事の中心 */
  if ( shutdown(sockfd, SHUT_RDWR) < 0 )     /* これ以上の送受信を禁止 */
    system ("/bin/stty cooked");
    error("cannot shutdown");
  close(sockfd);
  return 0;
}
