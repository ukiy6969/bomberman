#include "inet.h"                /* �����Ф�Ʊ�� inet.h ���� */
#define BUFSIZE 1024

void client(int fd)              /* ���饤����ȤλŻ����濴 */
{
  char b[BUFSIZE];
  int n;

  while ( fgets(b, BUFSIZE, stdin) != NULL ) {
    n = strlen(b);               /* n���ɤ߹����ʸ����(���Ԥ���)��Ĺ�� */
    b[n - 1] = '\0';             /* ����ʸ���ξ�˥̥�ʸ������ */
    printf("n = %d, b = \"%s\"\n", n, b);    /* ��ǧ�Τ������ */
    if ( write(fd, b, n) <= 0 )  /* �̥�ʸ����ޤ�ƥ����Ф��̿� */
        return;
  }
}

void error(char *s)              /* ���顼���� (�����Ф�Ʊ��) */
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
  bzero((char *)&sin, sizeof(sin));          /* sin �� 0 ��Ĥ�� */
  sin.sin_family = PF_INET;                  /* Internet �ɥᥤ�� */
  sin.sin_addr.s_addr = inet_addr(SERVER_ADDR); /* ���ɥ쥹�ϥ����� */
  sin.sin_port = htons(SERVER_PORT);         /* �ݡ��Ȥ� SERVER_PORT */
  if ( connect(sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0 )
    error("cannot connect");
  client(sockfd);                            /* ���饤����ȤλŻ����濴 */
  if ( shutdown(sockfd, SHUT_RDWR) < 0 )     /* ����ʾ����������ػ� */
    error("cannot shutdown");
  close(sockfd);
  return 0;
}
