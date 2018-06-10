#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct student{
      int sno;
};

//typedef struct student datatype;
typedef int datatype;
#define SIZE 40

typedef struct seqlist{
      datatype data[SIZE];
      int last;
}seq_list,*seq_plist;
extern seq_plist init_seqlist(void);
extern bool full_seqlist(seq_plist l);
extern void insert_seqlist(datatype data,seq_plist l);
extern bool empty_seqlist(seq_plist l);
extern void del_seqlist(datatype data,seq_plist l);
extern void show_seqlist(seq_plist l);


#endif
