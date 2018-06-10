#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char datatype_bt;

typedef struct btreenode{
      datatype_bt data;
      struct btreenode *lchild,*rchild;
}btree_node,*btree_pnode;

extern btree_pnode create_btree(void);
extern void pro_order(btree_pnode t);
extern void pro_order_2(btree_pnode t);
extern void mid_order(btree_pnode t);
extern void post_order(btree_pnode t);
extern void level_order(btree_pnode t);
extern void travel(const char *str,void (*fun)(btree_pnode),btree_pnode t);
#endif
