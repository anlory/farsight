#include "seqlist.h"

int main(void)
{
      seq_plist l;
      datatype data;
      int ret;

      l = init_seqlist();  //初始化顺序表    

      while(1){
	    printf("请输入整数:");
	    ret = scanf("%d",&data);	
	    if(ret == 0) //输入为字符
	      break;
	    else if(data > 0){	    //输入为正整数
		  insert_seqlist(data,l);
		  show_seqlist(l);
	    }else{	      //输入为负整数 
		  del_seqlist(-data,l);
		  show_seqlist(l);
	    }
      }

      return 0;
}

seq_plist init_seqlist(void)
{
      seq_plist p;

      p = (seq_plist)malloc(sizeof(seq_list));
      if(p == NULL){
	    perror("malloc");
	    exit(1);
      }
      p->last = -1;
      return p;
}

bool full_seqlist(seq_plist l)
{
      if(l->last == SIZE-1)
	    return true;
      else
	    return false;
}

void insert_seqlist(datatype data,seq_plist l)
{
      int i,j;
      if(full_seqlist(l)){
	    printf("The seqlist is full!\n");
	    return;
      }
      //寻找插入的位置
      for(i = 0; i <= l->last;i++)
	    if(data < l->data[i])
		  break;
      //向后移动后面的数据
      for(j = l->last; j >= i; j--)
	    l->data[j+1] = l->data[j];
      //插入新数据
      l->data[i] = data;
      //last++
      l->last++;
      return;
}

bool empty_seqlist(seq_plist l)
{
      if(l->last == -1)
	    return true;
      else
	    return false;
}

void del_seqlist(datatype data,seq_plist l)
{
      int i,j;
      if(empty_seqlist(l)){
	    printf("The seqlist is empty！\n");
	    return;
      }
      //寻找要删除的数据
      for(i = 0; i <= l->last; i++)
	    if(data == l->data[i])
		  break;
      //向前移动后面的数据
      if(i > l->last){ //data不存在
	    printf("%d is not in seqlist!\n",data);
	    return ;
      }else{
	    for(j = i;  j < l->last; j++)
		  l->data[j] = l->data[j+1];
      }
      //将 last--
      l->last--;
}

void show_seqlist(seq_plist l)
{
      int i;
      for(i = 0; i <= l->last;i++)
	    printf("%d\t",l->data[i]);
      printf("\n");
}
