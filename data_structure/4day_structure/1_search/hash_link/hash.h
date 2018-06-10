#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define p  13
typedef int datatype;
typedef struct list{
    datatype data;
    struct list * next;
}link_list,*link_plist;

typedef struct hashtbl{
    link_plist *h;
    int length;
}hash_tbl,*hash_ptbl;

extern void init_hash_link(int m,hash_ptbl * H);
extern void create_hash_link(int n,datatype *a,hash_ptbl hp);
extern link_plist search_hash_link(int key,hash_ptbl hp);
extern void show_hash_link(hash_ptbl hp);
#endif
