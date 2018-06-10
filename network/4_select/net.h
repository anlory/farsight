#ifndef __NET_H
#define __NET_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//#include <fcntl.h>
//#include <sys/stat.h>
#include <unistd.h>
//#include <netinet/in.h>
#include <sys/time.h>
//#include <sys/select.h>
//#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef int datatype;
typedef struct node
{
	datatype fd;
	struct node *next;
}node,*p_node;

extern void init_link(p_node*);
extern bool isempty(p_node);
extern bool insert_link(p_node,datatype);
extern bool del_link(p_node,datatype);

#define  err(str) ({perror(str);exit(1);})
#define PORT 8888
#define SRV_IP "192.168.7.5"
#define N 5
#endif

