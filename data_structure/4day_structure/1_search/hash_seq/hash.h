#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define p  13
typedef int datatype;

typedef struct hashtbl{
    datatype *h;
    int length;
}hash_tbl,*hash_ptbl;

extern void init_hash_seq(int m,hash_ptbl * H);
extern void create_hash_seq(int n,datatype *a,hash_ptbl hp);
extern int search_hash_seq(int key,hash_ptbl hp);
extern void show_hash_seq(hash_ptbl hp);
#endif
