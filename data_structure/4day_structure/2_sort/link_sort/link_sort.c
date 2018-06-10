#include "linklist.h"

void link_sort(link_plist l);
int main(void)
{
    link_plist l;
    int len;

    l = init_linklist();
    printf("请输入链表长度:");
    scanf("%d",&len); 
    create_linklist(len,l);
    show_linklist(l);
    link_sort(l);
    show_linklist(l);
}

void link_sort(link_plist l)
{
    link_plist p1,p2,q,p = l->next;
    l->next = NULL;

    while(p != NULL){
	q = p;     //q指向要插入的结点
	p = p->next;
	//在l指向的链表中循环寻找q的位置
	p1 = l;
	p2 = l->next;
	while((p2 != NULL) && (p2->data < q->data)){
	    p1 = p2;
	    p2 = p2->next;
	}
	//将q插入在p1和p2之间
	q->next = p2;
	p1->next = q;
    }

}
