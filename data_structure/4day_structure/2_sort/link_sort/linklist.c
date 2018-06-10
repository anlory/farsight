#include "linklist.h"

#ifdef DEBUG
int main(void)
{
      int len;
      link_plist l;

      l = init_linklist();
      printf("pls input length of list:");
      scanf("%d",&len);

      create_linklist(len,l);
      show_linklist(l);
      sort_linklist(l);
      show_linklist(l);
	return 0;
}
#endif
link_plist init_linklist(void)
{
      link_plist l;

      l = (link_plist)malloc(sizeof(link_list));
      if(NULL == l){
	    perror("malloc");
	    exit(-1);
      }
      l->next = NULL;
      return l;
}
void insert_linklist(link_plist new,link_plist p)
{
      new->next = p->next;
      p->next = new;
}
void del_linklist(link_plist p)
{
      link_plist q;

      q = p->next;
      p->next = q->next;
      free(q);
}

void create_linklist(int len,link_plist l)
{
      link_plist new,p = l;
      int i;

      for(i = 0; i < len; i++){
	    new = (link_plist)malloc(sizeof(link_list));
	    if(NULL == new){
		  perror("malloc");
		  exit(-1);
	    }
	    printf("请输入数据:");
	    scanf("%d",&new->data);
	    insert_linklist(new,p);
	    p = p->next;
      }

}

void sort_linklist(link_plist l)
{
      link_plist q,p = l->next;
      l->next = NULL;

      while(p){
	    q = p;
	    p = p->next;
	    insert_linklist(q,l);
	    show_linklist(l);
      }
}
bool empty_linklist(link_plist l)
{
      if(l->next == NULL)
	    return true;
      else
	    return false;
}

void show_linklist(link_plist l)
{
      link_plist p;
      for(p = l->next; p != NULL ; p = p->next)
	    printf("%d\t",p->data);
      printf("\n");
}

