#ifndef __SEQLIST_H__
#define __SEQLIST_H__


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10
struct student{
	int sno;
	char name[18];
	float score;
};

typedef struct student  datatype;

typedef struct seqlist{
	datatype data[SIZE];
	int last;
}seq_list,*seq_plist;


extern seq_plist init_seqlist(void);
extern void insert_seqlist(datatype d,seq_plist l);
extern void del_seqlist(datatype d,seq_plist l);
extern bool empty_seqlist(seq_plist l);
extern bool full_seqlist(seq_plist l);
extern void show_seqlist(seq_plist l);
#endif
