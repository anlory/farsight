#ifndef __NET_H__
#define __NET_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 5678
#define SRV_IP "192.168.7.5"
#define N 8
#define SIZE 50

char buf[SIZE];
char ip[16];
#endif
