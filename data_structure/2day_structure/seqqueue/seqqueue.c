#include "seqqueue.h"

#ifdef DEBUG
int main(void)
{
      seq_pqueue s;
      datatype data,t;
      int ret;

      s = init_seqqueue();  //初始化顺序表    

      while(1){
	    printf("请输入整数:");
	    ret = scanf("%d",&data);	
	    if(ret == 0){ //输入为字符,出栈
		  out_seqqueue(&t,s);	
		  printf("out is %d\n",t);
		  show_seqqueue(s);	  
		  while(getchar()!='\n');  //清空缓冲区
	    }else{	      //输入为整数,人栈 
		  in_seqqueue(data,s);
		  show_seqqueue(s);
	    }
      }

      return 0;
}
#endif
seq_pqueue init_seqqueue(void)
{
      seq_pqueue p;

      p = (seq_pqueue)malloc(sizeof(seq_queue));
      if(p == NULL){
	    perror("malloc");
	    exit(1);
      }
      p->front = p->rear = SIZE-1;
      return p;
}

bool full_seqqueue(seq_pqueue q)
{
      if((q->rear+1)%SIZE == q->front)
	    return true;
      else
	    return false;
}

void in_seqqueue(datatype data,seq_pqueue q)
{
      if(full_seqqueue(q)){
	    printf("The seqqueue is full!\n");
	    return;
      }
      //出对
      q->rear = (q->rear+1)%SIZE;
      q->data[q->rear] = data;
      return;
}

bool empty_seqqueue(seq_pqueue q)
{
      if(q->rear == q->front)
	    return true;
      else
	    return false;
}

void out_seqqueue(datatype* data,seq_pqueue q)
{
      if(empty_seqqueue(q)){
	    printf("The seqqueue is empty！\n");
	    return;
      }
      
      q->front = (q->front + 1)%SIZE;
      *data = q->data[q->front];
}     

void show_seqqueue(seq_pqueue q)
{
      int i;
      for(i = (q->front+1)%SIZE;i != (q->rear+1)%SIZE;i = (i+1)%SIZE)
	    printf("%d\t",q->data[i]);
      printf("\n");
}
