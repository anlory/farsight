#include "linkqueue.h"

#ifdef BUDEG
int main(void)
{
      datatype_lq data,tmp;
      link_pqueue q;
      int ret;

      init_linkqueue(&q);
      while(1){
	    printf("请输入整数:");
	    ret = scanf("%d",&data);
	    if(ret != 0){
		  in_linkqueue(data,q);
		  show_linkqueue(q);
	    }else{
		  if(out_linkqueue(&tmp,q)){
			printf("out is %d\n",tmp);
			show_linkqueue(q);
		  }
		  while(getchar() != '\n'); //清空缓冲区
	    }
      }
      return 0;
}
#endif
void init_linkqueue(link_pqueue *Q)
{
      *Q = (link_pqueue)malloc(sizeof(link_queue));
      if(*Q == NULL){
	    perror("malloc");
	    exit(1);
      }
      (*Q)->front = (list_pnode)malloc(sizeof(list_node));
      if((*Q)->front == NULL){
	    perror("malloc");
	    exit(1);
      }
      (*Q)->front->next = NULL;
      (*Q)->rear = (*Q)->front;
}

void in_linkqueue(datatype_lq data,link_pqueue q)
{
      list_pnode new;

      new = (list_pnode)malloc(sizeof(list_node));
      if(new == NULL){
	    perror("malloc");
	    exit(1);
      }
      new->data = data;

      //将new指向的新结点入对
      new->next = q->rear->next;
      q->rear->next = new;
      q->rear = new;
}

bool empty_linkqueue(link_pqueue q)
{
      if(q->front == q->rear)
	    return true;
      else
	    return false;
}

bool out_linkqueue(datatype_lq *T,link_pqueue q)
{
      list_pnode p;
      if(empty_linkqueue(q)){
	    printf("linkqueue is empty!\n");
	    return false;
      }

      //出对
      p = q->front;
      q->front = p->next;
      *T = q->front->data;
      free(p);
      return true;
}

#ifdef DEBUG
void show_linkqueue(link_pqueue q)
{
      list_pnode p;
      for(p = q->front->next; p != NULL; p = p->next)
	    printf("%d\t",p->data);
      printf("\n");
}
#endif

