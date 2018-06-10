#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct student{
      int sno;
};

//typedef struct student datatype;
typedef int datatype;
#define SIZE 8

typedef struct seqqueue{
      datatype data[SIZE];
      int front,rear;
}seq_queue,*seq_pqueue;
extern seq_pqueue init_seqqueue(void);
extern bool full_seqqueue(seq_pqueue l);
extern void in_seqqueue(datatype data,seq_pqueue l);
extern bool empty_seqqueue(seq_pqueue l);
extern void out_seqqueue(datatype* data,seq_pqueue l);
extern void show_seqqueue(seq_pqueue l);


#endif
