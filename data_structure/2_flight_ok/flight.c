#include "linklist.h"
#include "head.h"
#ifdef DEBUG
int main(void)
{
	int n;
	nodeflight_p h;//头指针

	flight_init(&h);

	printf("pls input length of list:");
	scanf("%d",&n);
	flight_create(h,n);
	flight_show(h);
	flight_sort(h);
	flight_show(h);
	return 0;
}
#endif
void flight_init(nodeflight_p * H)
{
	*H = (nodeflight_p)malloc(sizeof(nodeflight));
	if(NULL == *H){
		perror("malloc failed");
		exit(1);
	}
	(*H)->next = NULL;
}


void flight_del(nodeflight_p h)
{
	nodeflight_p p,q;
	for(p = h->next;p != NULL;){
			q = p;
			p = p->next;
			free(q);
	}
	h->next = NULL;
}
void flight_upload(nodeflight_p h)
{
	nodeflight_p new,p = h;
	FILE *fp;
	char buf[1024];
	char str_atime[10],str_stime[10];
	int n = 0;
	static int flag;

	flag++;
#if 0
	/*禁止多次加载信息*/
	if(flag > 1){
		printf("信息已加载过，不能在次加载!\n");
		return;
	}
#else
	/*可多次加载信息，但是在每次重新加载之前，需销毁已有的链表*/
	if(flag > 1)
		flight_del(p);
#endif

	if( (fp = fopen("flight.dat","r")) == NULL){
		perror("fopen");
		exit(1);
	}

	while(fgets(buf,1024,fp))
		n++;
	
	fseek(fp,0,SEEK_SET);
	
	while(n--){
		new = (nodeflight_p)malloc(sizeof(nodeflight));
		if(NULL == new){
			perror("malloc failed");
			exit(1);
		}
		fscanf(fp,"%s%s%s%s%s%s%s%d",new->data.number,new->data.staddress,\
				new->data.arraddress,new->data.date,new->data.type,\
				str_stime,str_atime,&(new->data.value));
		atoi_time(str_stime,&(new->data.stime));
		atoi_time(str_atime,&(new->data.atime));
		/*将new插入表尾*/
		new->next = p->next;
		p->next = new;
		p = p->next;
	}
	flight_sort(h);
	printf("第%d次从文件中加载信息!\n",flag);
}
void flight_create(nodeflight_p h)
{
	int i=0,n;
	nodeflight_p new,p = h;

	printf("你想输入几条信息？：");
	scanf("%d",&n);
	while(i < n){
		new = (nodeflight_p)malloc(sizeof(nodeflight));
		if(NULL == new){
			perror("malloc failed");
			exit(1);
		}
		scanf("%s%s%s%s%s%d%d%d",new->data.number,new->data.staddress,\
				new->data.arraddress,new->data.date,new->data.type,\
				&(new->data.stime),&(new->data.atime),&(new->data.value));

		/*将new插入头结点的后面，即表头位置*/
		new->next = p->next;
		p->next = new;

		p = new;
		i++;
	}
}

/*将int型时间转化成字符串,如：1030 转化为 10:30 */
void itoa_time(int t,char *str)
{
	char str1[6];
	int len,i;

	sprintf(str1,"%d",t);
	len = strlen(str1);
	for(i = len; i >= len-2; i--)
		str1[i+1] = str1[i];
	str1[i+1] = ':';
	strcpy(str,str1);
}
void flight_show(nodeflight_p h)
{
	nodeflight_p p;
	printf(RED"|------------------------------------------------------------------|\n");
	printf("| %-6s%-10s%-10s%-8s%-10s%-7s%-7s%-7s|\n",\
			"NO.","S_addr","A_addr","DATE","TYPE","ST","AT","Value");
	printf("|================================================================= |\n");
	for(p = h->next; p != NULL; p = p->next)
		info_show(p);
	printf("|------------------------------------------------------------------|\n");
	printf(NONE);
}

void flight_sort(nodeflight_p h)
{
	nodeflight_p p,q,r,u;
	p=h->next;       
	h->next=NULL;  
	while(p){ 
		r=h; q=h->next;  
		while ( q &&((q->data.stime) <= (p->data.stime))){
			r=q; 
			q=q->next; 
		}
		u=p->next;
		p->next=q; r->next=p; 
		p=u;
	} 
} 

/*将字符串转化成int型时间*/
void atoi_time(char *str,int *t)
{
#if 0
	*t = 0;
	while(*str){
		if(*str != ':')
			*t = *t * 10 + *str-'0';
		str++;
	}
#else
	int h,m;
	sscanf(str,"%d:%d",&h,&m);
	*t = h*100+m;
#endif
}

void flight_search(nodeflight_p h,char * str_key)
{
	/*根据起飞时间查询*/
	int key;
	nodeflight_p p = h->next;

	atoi_time(str_key,&key);
	printf(RED"|------------------------------------------------------------------|\n");
	printf("| %-6s%-10s%-10s%-8s%-10s%-7s%-7s%-7s|\n",\
			"NO.","S_addr","A_addr","DATE","TYPE","ST","AT","Value");
	printf("|================================================================= |\n");


	while(p != NULL){
		if(p->data.stime == key)
			info_show(p);
		p = p->next;
	}
	printf("|------------------------------------------------------------------|\n");
	printf(NONE);
}

void info_show(nodeflight_p p)
{
	char str_stime[10],str_atime[10];

	itoa_time(p->data.stime,str_stime);

	itoa_time(p->data.atime,str_atime);
	printf(RED"| %-6s%-10s%-10s%-8s%-8s%-8s %-8s%-6d|\n",\
			p->data.number,p->data.staddress,\
			p->data.arraddress,p->data.date,p->data.type,\
			str_stime,str_atime,p->data.value);
}
