#include "doublelink.h"

double_plist init_doublelist()
{
	double_plist h;

	h = (double_plist)malloc(sizeof(double_list));
	if(NULL == h){
		printf("malloc failed\n");
		exit(1);
	}

	INIT_LIST_HEAD(&h->list);
	return h;
}
void create_doublelist(int n,double_plist h)
{
	int i;
	double_plist new;
	for(i = 0; i < n; i++){
		new = (double_plist)malloc(sizeof(double_list));
		if(NULL == new){
			printf("malloc failed\n");
			exit(1);
		}
		new->data = i+1;

		list_add_tail(&new->list,&h->list);
		show_doublelist(h);
		sleep(1);
	}
}

void sort_doublelist(double_plist h)
{
	double_plist q,p,t;

	p = list_entry(h->list.next,double_list,list);
	t = list_entry(h->list.prev,double_list,list);
	while(p != t){
		if(p->data%2 != 0)
		    p = list_entry(p->list.next,double_list,list);
		else{
			q = p;
			p = list_entry(p->list.next,double_list,list);
			list_move(&q->list,&t->list);
		}
		show_doublelist(h);
		sleep(1);
	}
}

void show_doublelist(double_plist h)
{
	double_plist p;
        list_for_each_entry(p,&h->list,list)
		printf("%d\t",p->data);
	printf("\n");
}


