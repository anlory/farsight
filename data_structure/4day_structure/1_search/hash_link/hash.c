#include "hash.h"

int main(void)
{
    datatype a[11] = {23,34,14,38,46,16,68,15,7,31,26};
    hash_ptbl hp;
    int m,sno;
    link_plist ret;
    char ch;

    init_hash_link(p,&hp);

    create_hash_link(11,a,hp);
#if 1
    while(1){
	printf("请输入要查找的数据的关键字(学号)：");
	scanf("%d",&sno);
	ret = search_hash_link(sno,hp);
	if(ret == NULL)
	    printf("您要查找数据不存在!\n");
	else{
	    printf("您要查找的记录存在,为：%d\n",ret->data);
	}
	printf("是否继续(Y/N)?");
	getchar();
	scanf("%c",&ch);
	if((ch == 'Y')||(ch == 'y'))
	    continue;
	else
	    break;
    }
#endif
    return 0;
}

void init_hash_link(int m,hash_ptbl * H)
{
    int i;
    *H = (hash_ptbl)malloc(sizeof(hash_tbl));
    if(NULL == *H){
	perror("malloc");
	exit(-1);
    }
    (*H)->length = m;
    (*H)->h = (link_plist*)malloc(sizeof(link_plist)*m);
    if(NULL == (*H)->h){
	perror("malloc");
	exit(-1);
    }
    for(i = 0; i < m; i++)
	(*H)->h[i] = NULL;
}
void create_hash_link(int n,datatype *a,hash_ptbl hp)
{
    int i;
    int hash_val;
    link_plist new;

    for(i = 0; i < n; i++){
	hash_val = a[i]%p;  //保留余数构造hash函数
	//链地址法处理冲突
	new = (link_plist)malloc(sizeof(link_list));
	if(NULL == new){
	    perror("malloc");
	    exit(-1);
	}
	new->data = a[i];
	//将新结点插入到hash_val位置的指针指向的链表
	new->next = hp->h[hash_val];
	hp->h[hash_val] = new;
	show_hash_link(hp);
	sleep(1);
    }
}
#if 1
link_plist search_hash_link(int key,hash_ptbl hp)
{
    int hash_val,i= 0;
    link_plist q;

    hash_val = key % p;
    q = hp->h[hash_val];
    while(q != NULL){
	if(q->data == key)
	    return q;
	q = q->next;
    }
    return NULL;
}
#endif
void show_hash_link(hash_ptbl hp)
{
    int i;
    link_plist q;
    for(i = 0; i < hp->length; i++){
	q = hp->h[i];
	printf("hp->h[%02d]",i);
	if(q == NULL)
	    printf("%p",hp->h[i]);
	while(q != NULL){
	    printf("--->%02d",q->data);
	    q = q->next;
	}
	printf("\n");
    }
    printf("***************************\n");
}
