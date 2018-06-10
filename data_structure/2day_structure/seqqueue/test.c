#include "seqstack.h"

int main(void)
{
      datatype data,tmp;
      seq_pstack top;

      top = init_seqstack(); //初始化一个空栈 
      printf("请输入一个十进制整数:");
      scanf("%d",&data);
      if(data > 0)
	    tmp = data;
      else
	    tmp = -data;
      while(tmp != 0){
	    push_seqstack(tmp%8,top);
	    tmp /= 8;
      }
      if(data > 0)
	    printf("十进制%d转化成八进制为0",data);
      else
	    printf("十进制%d转化成八进制为-0",data);
      while(!empty_seqstack(top)){
	    pop_seqstack(&tmp,top);
	    printf("%d",tmp);
      }
      printf("\n");
      return 0;
}
