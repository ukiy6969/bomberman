/*
 *   inet.h   2012.09.10
 */
#include <stdio.h>
#include <stdlib.h>                 /* exit��ɬ�� */
#include <string.h>                 /* strlen��ɬ�� */
#include <strings.h>                /* bzero��ɬ��*/
#include <sys/types.h>              /* socket �ʤɤΥ����ƥॳ�����ɬ�� */
#include <sys/socket.h>             /*    Ʊ��  */
#include <netinet/in.h>             /* struct sockaddr_in �����Ѥ�ɬ�� */
#include "string.h"
#include "game.h"

#define SERVER_ADDR "127.0.0.1"  /* �����ФΥ��ɥ쥹�������ϳƼ��Ѥ��� */
#define  STUDENT_ID  196             /* ��ʬ�γ����ֹ�β�3������������Ƽ��Ѥ��� */
#define PORT_BASE   12000
#define SERVER_PORT (PORT_BASE+STUDENT_ID) /* ���եݡ����ֹ� */
