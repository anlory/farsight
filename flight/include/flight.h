#ifndef _FLIGHT_H_
#define _FLIGHT_H_

#include"print.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct flight
{
	char number[18];//航班号
	char staaddress[18];//起点
	char arraddress[18];//终点
	char DATE[12];//班期
	char TYPE[8];//机型
	int stime;//起飞时间
	int atime;//到达时间
	int value;//票价
}flight_data,*flight_pdata;

typedef struct node{
	flight_pdata flight;
	struct node *next;
}flight_node,*flight_pnode;  //链表指针

extern void read_flight(void);//加载flight.txt文本航班信息
extern void itoa(int t,char *str);//整型数据变时间格式
extern void search(void);//查询
extern flight_pdata hsearch_flight(char*hnum,flight_pnode fnode);//航班号查询
extern flight_pdata nsearch_flight(char*hnode,flight_pnode fnode);
//班期查询
extern flight_pdata tsearch_flight(int time,flight_pnode fnode);
//起飞时间查询
extern void show_search(flight_pdata p);
//显示信息

extern void menu_1(void);//主页面
extern void menu_in(void);//输入信息页面
extern void men_search(void);//查询页面
extern void insert(void);//输入



extern void insert_flight(void);//输入航班信息
extern int in_fnode(flight_pdata new,flight_pnode fnode);//插入链表
extern flight_pnode init_fnode(void);//初始化链表信息
#endif
