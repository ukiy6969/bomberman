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
  pthread_t th;
  bomb_args bargs;
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
      if ( c== '.') {
        system("/bin/stty cooked");
        return;
      }
      if ( (c == KEY_UP) || (c == KEY_DOWN)
            || (c == KEY_LEFT) || (c == KEY_RIGHT) ) {
        move(g,position, c);
        print_field(g);
        snprintf(b, BUFSIZE, "%d", c);
        write(fd, b, BUFSIZE);
      }
      if ( (c == BOMB) && !g->m_is_bomb) {
        bomb_args bargs = { 2, g };
        if ( g->position == 0) {
          if (set_bomb_m(g) ){
            pthread_create( &th, NULL, bomb_thread_m, &bargs);
            snprintf(b, BUFSIZE, "%d", c);
            write(fd, b, BUFSIZE);
          }
        }else if (g->position == 1) {
          set_bomb_a(g);
          pthread_create( &th, NULL, bomb_thread_a, &bargs);
          snprintf(b, BUFSIZE, "%d", c);
          write(fd, b, BUFSIZE);
        }
        print_field(g);
      }
    }
    if ( FD_ISSET(fd, &fds) ) {
      n = read(fd, b, BUFSIZE);
      c = atoi(b);
      if ( (c == KEY_UP) || (c == KEY_DOWN)
            || (c == KEY_LEFT) || (c == KEY_RIGHT) ) {
        move(g,position^1, c);
        print_field(g);
      }
      if ( (c == BOMB) && !g->m_is_bomb) {
        bomb_args bargs = { 2, g };
        if ( g->position == 0) {
          set_bomb_a(g);
          pthread_create( &th, NULL, bomb_thread_a, &bargs);
        }else if (g->position == 1) {
          set_bomb_m(g);
          pthread_create( &th, NULL, bomb_thread_m, &bargs);

        }
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
  if(read(fd, b, BUFSIZE) > 0) {
    n = atoi(b);
    printf("%d\n", n);
    position = n;
    g->position = n;
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
