#include "seqlist.h"
void create_list(seq_plist *L)
{
	int i,n;

	printf("请输入顺序表长度:");
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d%s%f",&(*L)->data[i].sno,(*L)->data[i].name,&(*L)->data[i].score);
		(*L)->last++;
	}
}
//顺序查找算法
int search_seq(seq_plist l,int key)
{
	int i;
	for(i = l->last; i>=0; i--)
		if(l->data[i].sno == key)
			return i;
	return -1;
}

int main(void)
{
	int key;
	int ret;

	seq_plist l;
	l = init_seqlist();
	create_list(&l);
	show_seqlist(l);
	//在顺序表l中查找关键字位key的记录
	printf("请输入关键字key:");
	scanf("%d",&key);

	ret = search_seq(l,key);
	if(ret == -1)
		printf("要查找的关键字%d不在顺序表中!\n",key);
	else{
		printf("要查找的关键字%d在顺序表的第%d个位置!\n",key,ret);
		printf("该记录是:%d\t%s\t%f\n",l->data[ret].sno,l->data[ret].name,l->data[ret].score);
	}
	return 0;
}



