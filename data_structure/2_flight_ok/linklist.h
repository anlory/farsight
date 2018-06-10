#ifndef __LINKLIST_H
#define __LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

#define N 18

typedef struct flight{
	char number[N];     //航班号
	char staddress[N];  //起点站
	char arraddress[N]; //终点站
	char date[N];    //班期
	char type[N];    //机型
	int stime;      //起飞时间
	int atime;     //到达时间
	int value;     //票价
}datatype;

typedef struct node{
    datatype data;
    struct node *next;
}nodeflight,*nodeflight_p;

/*单向链表初始化*/
extern void flight_init(nodeflight_p * H);

/*创建单向链表*/
extern void flight_create(nodeflight_p h);

/*从文件中加载信息到单向链表中*/
extern void flight_upload(nodeflight_p h);

/*打印单向链表中的信息*/
extern void flight_show(nodeflight_p h);

/*对单向链表中的信息排序*/
extern void flight_sort(nodeflight_p h);

/*根据关键字key在单向链表中查找信息记录*/
extern void flight_search(nodeflight_p h,char* key);

/*将字符串转化成int型时间*/
extern void atoi_time(char *str,int *t);

/*将int型时间转化成字符串,如：1030 转化为 10:30 */
extern void itoa_time(int t,char *str);

/*显示一条信息*/
extern void info_show(nodeflight_p p);

/*销毁链表中的信息*/
extern void flight_del(nodeflight_p h);
#endif
