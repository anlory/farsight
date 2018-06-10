#include "seqstack.h"

int main(void)
{
      seq_pstack s;
      datatype data,t;
      int ret;

      s = init_seqstack();  //初始化顺序表    

      while(1){
	    printf("请输入整数:");
	    ret = scanf("%d",&data);	
	    if(ret == 0){ //输入为字符,出栈
		  pop_seqstack(&t,s);	
		  printf("pop is %d\n",t);
		  show_seqstack(s);	  
		  while(getchar()!='\n');  //清空缓冲区
	    }else{	      //输入为整数,人栈 
		  push_seqstack(data,s);
		  show_seqstack(s);
	    }
      }

      return 0;
}

seq_pstack init_seqstack(void)
{
      seq_pstack p;

      p = (seq_pstack)malloc(sizeof(seq_stack));
      if(p == NULL){
	    perror("malloc");
	    exit(1);
      }
      p->top = -1;
      return p;
}

bool full_seqstack(seq_pstack s)
{
      if(s->top == SIZE-1)
	    return true;
      else
	    return false;
}

void push_seqstack(datatype data,seq_pstack s)
{
      if(full_seqstack(s)){
	    printf("The seqstack is full!\n");
	    return;
      }
      //入栈
      s->top++;
      s->data[s->top] = data;
      return;
}

bool empty_seqstack(seq_pstack s)
{
      if(s->top == -1)
	    return true;
      else
	    return false;
}

void pop_seqstack(datatype* data,seq_pstack s)
{
      if(empty_seqstack(s)){
	    printf("The seqstack is empty！\n");
	    return;
      }
      
      *data = s->data[s->top];
      s->top--;
}     

void show_seqstack(seq_pstack s)
{
      int i;
      for(i = 0; i <= s->top;i++)
	    printf("%d\t",s->data[i]);
      printf("\n");
}
