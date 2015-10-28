#include "inet.h"                /* サーバと同じ inet.h を共用 */
#define BUFSIZE 1024

void client(int fd)              /* クライアントの仕事の中心 */
{
  char b[BUFSIZE];
  int n;

  while ( fgets(b, BUFSIZE, stdin) != NULL ) {
    n = strlen(b);               /* nは読み込んだ文字列(改行あり)の長さ */
    b[n - 1] = '\0';             /* 改行文字の上にヌル文字を上書き */
    printf("n = %d, b = \"%s\"\n", n, b);    /* 確認のため出力 */
    if ( write(fd, b, n) <= 0 )  /* ヌル文字も含めてサーバに通信 */
        return;
  }
}

void error(char *s)              /* エラー処理 (サーバと同じ) */
{
  perror(s);
  exit(1);
}

int main(int argc, char **argv)
{
  int sockfd;
  struct sockaddr_in sin;

  if ( (sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0 ) /* socket */
    error("cannot create socket");
  bzero((char *)&sin, sizeof(sin));          /* sin に 0 をつめる */
  sin.sin_family = PF_INET;                  /* Internet ドメイン */
  sin.sin_addr.s_addr = inet_addr(SERVER_ADDR); /* アドレスはサーバ */
  sin.sin_port = htons(SERVER_PORT);         /* ポートは SERVER_PORT */
  if ( connect(sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0 )
    error("cannot connect");
  client(sockfd);                            /* クライアントの仕事の中心 */
  if ( shutdown(sockfd, SHUT_RDWR) < 0 )     /* これ以上の送受信を禁止 */
    error("cannot shutdown");
  close(sockfd);
  return 0;
}
