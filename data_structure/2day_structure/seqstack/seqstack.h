#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct student{
      int sno;
};

//typedef struct student datatype;
typedef int datatype;
#define SIZE 40

typedef struct seqstack{
      datatype data[SIZE];
      int top;
}seq_stack,*seq_pstack;
extern seq_pstack init_seqstack(void);
extern bool full_seqstack(seq_pstack l);
extern void push_seqstack(datatype data,seq_pstack l);
extern bool empty_seqstack(seq_pstack l);
extern void pop_seqstack(datatype* data,seq_pstack l);
extern void show_seqstack(seq_pstack l);


#endif
