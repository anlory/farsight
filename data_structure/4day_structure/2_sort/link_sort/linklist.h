#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;

typedef struct linklist{
      datatype data;
      struct linklist *next;
}link_list,*link_plist;


extern link_plist init_linklist(void);
extern void insert_linklist(link_plist new,link_plist p);
extern void del_linklist(link_plist p);
extern void create_linklist(int len,link_plist l);
extern  bool empty_linklist(link_plist l);
extern void sort_linklist(link_plist l);
extern void show_linklist(link_plist l);
#endif
