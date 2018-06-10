#ifndef __DOUBLELINK_H__
#define __DOUBLELINK_H__


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef int datatype;

typedef struct doublenode{
	datatype data;
	struct doublenode *next,*prior;
}double_list,*double_plist;

extern double_plist init_doublelist();
extern void pro_insert_doublelink(double_plist new,double_plist p);
extern void post_insert_doublelink(double_plist new,double_plist p);
extern void cur_move_doublelink(double_plist p);
extern void create_doublelist(int n,double_plist h);
extern void sort_doublelist(double_plist h);
extern void show_doublelist(double_plist h);
#endif
