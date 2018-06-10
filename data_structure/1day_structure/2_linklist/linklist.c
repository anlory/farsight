#include "linklist.h"

int main(void)
{
      link_plist h;

      h = init_linklist();  //初始化单向链表
      create_linklist(h);  //创建链表
      show_linklist(h);
      sort_linklist(h);  //对链表进行逆序处理
      show_linklist(h);

      return 0;
}

link_plist init_linklist(void)
{
      link_plist p;

      //申请头结点空间
      p = (link_plist)malloc(sizeof(link_list));
      if(p == NULL){
	    perror("malloc");
	    exit(1);
      }
      p->next = NULL;
      return p;
}

void create_linklist(link_plist h)
{
      int n,i;
      link_plist new,p = h;

      printf("请输入链表中的元素个数:");
      scanf("%d",&n);
      for(i = 0; i < n; i++){
	    new = (link_plist)malloc(sizeof(link_list));
	    if(new == NULL){
		  perror("malloc");
		  exit(1);
	    }
	    scanf("%d",&new->data);
	    new->next = p->next;
	    p->next = new;

	    p = p->next;
      }
}

bool empty_linklist(link_plist h)
{
      if(h->next == NULL)
	    return true;
      else
	    return false;
}

void sort_linklist(link_plist h)
{
      link_plist q,p;

      if(empty_linklist(h)){
	    printf("链表为空!\n");
	    exit(1);
      }

      p = h->next;
      h->next = NULL;

      while(p != NULL){
	    q = p;
	    p = p->next;

	    q->next = h->next;
	    h->next = q;
      }
}

void show_linklist(link_plist h)
{
      link_plist p;
      for(p = h->next; p != NULL; p = p->next)
	    printf("%d\t",p->data);
      printf("\n");
}
