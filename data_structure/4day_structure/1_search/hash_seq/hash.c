#include "hash.h"

int main(void)
{
    datatype a[11] = {23,34,14,38,46,16,68,15,7,31,26};
    hash_ptbl hp;
    int m,ret,sno;
    char ch;

    //获得hash表的长度
    m = ceil(11/0.75); //向上取整

    //初始化hash表
    init_hash_seq(m,&hp);

    create_hash_seq(11,a,hp); //构造hash表
    while(1){
	printf("请输入要查找的数据的关键字(学号)：");
	scanf("%d",&sno);
	ret = search_hash_seq(sno,hp);
	if(ret == -1)
	    printf("您要查找数据不存在!\n");
	else{
	    printf("您要查找的记录在下标为%d的位置!\n",ret);
	    printf("该数据是：%d\n",hp->h[ret]);
	}
	printf("是否继续(Y/N)?");
	getchar();
	scanf("%c",&ch);
	if((ch == 'Y')||(ch == 'y'))
	    continue;
	else
	    break;
    }

    return 0;
}

void init_hash_seq(int m,hash_ptbl * H)
{
    int i;
    *H = (hash_ptbl)malloc(sizeof(hash_tbl));
    if(NULL == *H){
	perror("malloc");
	exit(-1);
    }
    (*H)->length = m;
    (*H)->h = (datatype*)malloc(sizeof(datatype)*m);
    if(NULL == (*H)->h){
	perror("malloc");
	exit(-1);
    }
    for(i = 0; i < m; i++)
	(*H)->h[i] = -1;
}
void create_hash_seq(int n,datatype *a,hash_ptbl hp)
{
    int i;

    int hash_val;

    for(i = 0; i < n; i++){
	hash_val = a[i]%p;  //保留余数构造hash函数

	//线性探查法处理冲突
	while(hp->h[hash_val] != -1){
	    hash_val = (hash_val + 1) % hp->length;
	}
	hp->h[hash_val] = a[i]; //将记录存入hash_val所在的位置  
	show_hash_seq(hp);
	sleep(1);
    }
}

int search_hash_seq(int key,hash_ptbl hp)
{
    int hash_val,flag= 0;

    hash_val = key % p;  //除留余数法获得hash地址

    while(hp->h[hash_val] != key){//判断hash_val中的key是否和要查找的key相同，如果不相同，则地址加1，继续判断
	hash_val = (hash_val + 1) % hp->length;
	flag++;
	if(flag > hp->length) //如果将hash表中所有记录的key都与key比较，没有找到和key相等的记录，则该记录不存在，返回-1
	    return -1;
    }
    return hash_val;
}

void show_hash_seq(hash_ptbl hp)
{
    int i;
    for(i = 0; i < hp->length; i++){
	printf("hp->h[%02d]:%02d\n",i,hp->h[i]);
    }
    printf("***************************\n");
}
