#include "doublelink.h"

double_plist init_doublelist()
{
	double_plist h;

	h = (double_plist)malloc(sizeof(double_list));
	if(NULL == h){
		printf("malloc failed\n");
		exit(1);
	}

	h->next = h->prior = h;
	return h;
}
//向p指向的结点前面插入new指向的结点
void pro_insert_doublelink(double_plist new,double_plist p)
{
	new->prior = p->prior;
	p->prior->next = new;
	new->next = p;
	p->prior = new;
}
//向p指向的结点后面插入new指向的结点
void post_insert_doublelink(double_plist new,double_plist p)
{
	new->next = p->next;
	p->next->prior = new;
	new->prior = p;
	p->next = new;
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

		pro_insert_doublelink(new,h);//向表尾插入new
		show_doublelist(h);
		sleep(1);
	}
}

//剪切p指向的结点
void cur_move_doublelink(double_plist p)
{
			p->prior->next = p->next;
			p->next->prior = p->prior;
}

void sort_doublelist(double_plist h)
{
	double_plist q,p,t;

	p = h->next;
	t = h->prior;
	while(p != t){
		if(p->data%2 != 0)
			p = p->next;
		else{
			q = p;
			p = p->next;
			//剪切q
			cur_move_doublelink(q);
			//将q指向的结点插入t结点的后面
			post_insert_doublelink(q,t);
		}
	}
}

void show_doublelist(double_plist h)
{
	double_plist p = h->next;

	while(p != h){
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}


