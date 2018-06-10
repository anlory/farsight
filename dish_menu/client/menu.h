#ifndef _MENU_H_
#define _MENU_H_
#include"print.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sqlite3.h>
#include"cJSON.h"
#include<sys/socket.h>
#include<sys/file.h>
#include<sys/stat.h>
#include<arpa/inet.h>
#include<pthread.h>
#include<signal.h>
#include<semaphore.h>

#define PORT 8888
#define IP "192.168.7.100"
#define SIZE 2048

char *bufsnd ,*bufget;
sem_t sem;//同步信号
char *a[100][4];//菜单数组
char *b[100][4];//订单数组

int ma,na;//菜单数组行和列
int mb,nb;//订单数组行和列
int sum;//总账
int pay_sig,hurry_sig;//结帐，催促符号
int sock_fd;//套接字
int number;//桌号


/*发送订单*/
extern void send_array_json(void );

/*处理催促和结帐信号*/
extern void my_func(int sign_no);

/*处理服务器发的json数据*/
extern void  change_json_array(void);

/*打印订单*/
extern void show_menu( void);


/*点菜*/
extern void order_dish(void);

/*结帐*/
extern void pay_bill(void);

/*催促*/
extern void hurry(void);

/*关闭*/
extern void shut(void);

#endif
