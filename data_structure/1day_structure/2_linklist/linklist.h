#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct student{
      int sno;
};

//typedef struct student datatype;
typedef int datatype;
#define SIZE 40

typedef struct linklist{
      datatype data;
      struct linklist *next;
}link_list,*link_plist;

extern link_plist init_linklist(void);
extern void create_linklist(link_plist h);
extern bool empty_linklist(link_plist l);
extern void sort_linklist(link_plist h);
extern void show_linklist(link_plist l);


#endif
