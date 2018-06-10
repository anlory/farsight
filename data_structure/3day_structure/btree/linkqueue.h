#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "btree.h"

typedef btree_pnode datatype_lq;

typedef struct node{
      datatype_lq data;
      struct node *next;
}list_node,*list_pnode;

typedef struct linkqueue{
      list_pnode front,rear;
}link_queue,*link_pqueue;

extern void init_linkqueue(link_pqueue *Q);
extern void in_linkqueue(datatype_lq data,link_pqueue q);
extern bool out_linkqueue(datatype_lq *T,link_pqueue q);
#ifdef DEBUG
extern void show_linkqueue(link_pqueue q);
#endif
extern bool empty_linkqueue(link_pqueue q);

#endif
