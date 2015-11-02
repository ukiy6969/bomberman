/*
 *   inet.h   2012.09.10
 */
#include <stdio.h>
#include <stdlib.h>                 /* exitに必要 */
#include <string.h>                 /* strlenに必要 */
#include <strings.h>                /* bzeroに必要*/
#include <sys/types.h>              /* socket などのシステムコールに必要 */
#include <sys/socket.h>             /*    同上  */
#include <netinet/in.h>             /* struct sockaddr_in の利用に必要 */
#include "string.h"
#include "game.h"

#define SERVER_ADDR "127.0.0.1"  /* サーバのアドレス，ここは各自変える */
#define  STUDENT_ID  196             /* 自分の学籍番号の下3けた，ここも各自変える */
#define PORT_BASE   12000
#define SERVER_PORT (PORT_BASE+STUDENT_ID) /* 受付ポート番号 */
