#include "seqlist.h"

seq_plist init_seqlist(void)
{
	seq_plist p;

	p = (seq_plist)malloc(sizeof(seq_list));
	if(NULL == p){
		printf("malloc failed!\n");
		exit(-1);
	}
	p->last = -1;
	return p;
}

void insert_seqlist(datatype d,seq_plist l)
{
	int i,j;

	if(full_seqlist(l))
		return;
	//寻找插入的位置
	for(i = 0; i <= l->last; i++)
		if(d.sno <l->data[i].sno)
			break;
	//i的位置就是插入d的位置,将从i开始的数据向后移动
	for(j = l->last; j>=i;j--)
		l->data[j+1] = l->data[j];
	l->data[i] = d;
	l->last++;
}	

void del_seqlist(datatype d,seq_plist l)
{
	int i,j;
	if(empty_seqlist(l))
		return;
	//寻找要删除的数据
	for(i = 0; i <= l->last; i++)
		if(d.sno == l->data[i].sno)
			break;
	if(i == l->last+1)
		printf("%d不存在!\n",d.sno);
	else{
		for(j = i; j < l->last; j++)
			l->data[j] = l->data[j+1];
		l->last--;
	}
}

bool empty_seqlist(seq_plist l)
{
	if(l->last == -1)
		return true;
	else
		return false;
}
bool full_seqlist(seq_plist l)
{
	if(l->last == SIZE-1)
		return true;
	else
		return false;
}

void show_seqlist(seq_plist l)
{
	int i;
	for(i = 0; i <= l->last; i++)
		printf("%d\t%s\t%f\n",l->data[i].sno,l->data[i].name,l->data[i].score);
}

