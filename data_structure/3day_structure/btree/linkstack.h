#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "btree.h"

struct student{
      int sno;
};

//typedef struct student datatype;
typedef btree_pnode datatype;
#define SIZE 40

typedef struct linkstack{
      datatype data;
      struct linkstack *next;
}link_stack,*link_pstack;
extern link_pstack init_linkstack(void);
extern void push_linkstack(datatype data,link_pstack* l);
extern bool empty_linkstack(link_pstack l);
extern void pop_linkstack(datatype* data,link_pstack* l);
#ifdef DEBUG
extern void show_linkstack(link_pstack l);
#endif

#endif
