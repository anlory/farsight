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

#define err(ptr) ({	perror(ptr);exit(1);} )


/*json 订单插入到bill数据表中,返回桌号*/
extern  int  get_json_sqlite(char *out,char *addr );

/*将数据库中数据转化为json*/
extern void change_sqlite_json( char ** out);

/*打印菜单*/
extern void show_menu(void);

/*管理菜单*/
extern void ctl_menu(void);

/*打印订单*/
extern void show_bill(void);

/*显示总营业额*/
extern void show_total(void);

/*总帐插入到total数据表*/
extern void total_into(int sum);



#endif
