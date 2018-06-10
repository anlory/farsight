#include "linkstack.h"

int main(void)
{
      link_pstack top;
      datatype data,t;
      int ret;

      top = init_linkstack();  //初始化顺序表    

      while(1){
	    printf("请输入整数:");
	    ret = scanf("%d",&data);	
	    if(ret == 0){ //输入为字符,出栈
		  pop_linkstack(&t,&top);	
		  printf("pop is %d\n",t);
		  show_linkstack(top);	  
		  while(getchar()!='\n');  //清空缓冲区
	    }else{	      //输入为整数,人栈 
		  push_linkstack(data,&top);
		  show_linkstack(top);
	    }
      }

      return 0;
}

link_pstack init_linkstack(void)
{
      return NULL;
}

void push_linkstack(datatype data,link_pstack * Top)
{
      link_pstack new;

      //入栈
      new = (link_pstack)malloc(sizeof(link_stack));
      if(new == NULL){
	    printf("malloc failed!\n");
	    return ;
      }
      new->data = data;
      new->next = *Top;
      *Top = new;
      return;
}

bool empty_linkstack(link_pstack top)
{
      if(top == NULL)
	    return true;
      else
	    return false;
}

void pop_linkstack(datatype* data,link_pstack *Top)
{
      link_pstack p;
      if(empty_linkstack(*Top)){
	    printf("The linkstack is empty！\n");
	    return;
      }
      
      p = *Top;
      (*Top) = (*Top)->next;
      *data = p->data;
      free(p);
}     

void show_linkstack(link_pstack top)
{
      link_pstack p;
      
      for(p = top; p != NULL; p = p->next)
	    printf("%d\t",p->data);
      printf("\n");
}
