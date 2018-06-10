#include"../include/flight.h"
extern void delete_flight(void);
void insert(void)
{
	extern flight_pnode fnode;
	int data;
	menu_in();
	scanf("%d",&data);
	if(data==1)
		insert_flight();//输入信息

	if(data==2)
		read_flight();//加载信息

	if(data==3)
		delete_flight();//删除信息
		
	if(data==4)
		return ;
}

void delete_flight(void)
{
	char num[18];
	printf("请输入需要删除的航班号:");
	while(getchar()!='\n');
	scanf("%s",num);
	flight_pnode p,q;
	extern flight_pnode fnode;
	p=fnode;
	q=p->next;
	while(q!=NULL)
		{
		 if(strcmp(q->flight->number,num)==0)
			{
				p->next=q->next;
				free(q);
			}
			p=p->next;
			q=q->next;
		}


}






void insert_flight(void)//输入信息
{
	int flag=1;
	extern flight_pnode fnode;
	flight_pdata new;
	while(1)
	{		
	flag=in_fnode(new,fnode);
	if(flag==0)
		{		
		break;
		}
	}
}

flight_pnode init_fnode(void)//初始化链表
{
	extern flight_pnode fnode;
	fnode=malloc(sizeof(flight_node));
	if(fnode==NULL)
	{
		perror("malloc");
		exit(1);
	}
	fnode->next=NULL;
	return fnode;
}

int in_fnode(flight_pdata new,flight_pnode fnode)//输入
{
	char flag;
	new=malloc(sizeof(flight_data));
	if(new==NULL)
	{
		perror("malloc");
		exit(1);
	}
	while(getchar()!='\n');
	printf("输入航班信息 ?  y/n \n");
	scanf("%c",&flag);
	if(flag=='y'||flag=='Y')
	{
		printf("请输入航班号\n");
		scanf("%s",new->number);
		printf("请输入航班起点\n");
		scanf("%s",new->staaddress);
		
		printf("请输入航班终点\n");
		scanf("%s",new->arraddress);
		
		printf("请输入航班日期\n");
		scanf("%s",new->DATE);
		
		printf("请输入航班机型\n");
		scanf("%s",new->TYPE);
		
		printf("请输入起飞时间\n");
		scanf("%6d",&new->stime);
		
		printf("请输入到达时间\n");
		scanf("%6d",&new->atime);
		
		printf("请输入票价\n");
		scanf("%4d",&new->value);
	}
	else
		return 0;
	flight_pnode p,q1,q2;
	p=malloc (sizeof(flight_pnode));
	p->next=NULL;
	p->flight=new;
	q1=fnode;
	q2=fnode->next;
	while(q2&&q2->flight->stime<new->stime)//录入数据的时候顺便起飞时间排序
	{

		q1=q2;
		q2=q2->next;
	}
	q1->next=p;
	p->next=q2;
	return 1;
}

void read_flight(void)
{
	extern flight_pnode fnode;
	flight_pdata new;
	int i;
	FILE *fp; 
	fp=fopen("flight.txt","r");
	if (fp==NULL)
		 {perror("fopen");
			return ;
		 }
	
	int ret=1;
	while(ret!=EOF)//加载文本结束时停止
	{
	new=malloc(sizeof(flight_data));
	if(new==NULL)
		{
		perror("malloc");
		exit(1);
		}
	ret =fscanf(fp,"%s%s%s%s%s%d%d%d",new->number,new->staaddress,\
				new->arraddress,new->DATE,new->TYPE,&new->stime,\
				&new->atime,&new->value);
	if(ret==EOF)  
		break;
	flight_pnode p,q1,q2;
	p=malloc (sizeof(flight_pnode));
	p->next=NULL;
	p->flight=new;
	q1=fnode;
	q2=fnode->next;
	while(q2&&q2->flight->stime<new->stime)//录入数据的时候顺便排序
		{
		q1=q2;
		q2=q2->next;
		}
	q1->next=p;
	p->next=q2;	
	}
	printf("加载完毕\n");
	}
