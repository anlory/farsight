#include"../include/flight.h"
void search(void)
{
	extern flight_pnode fnode;
	int data;
	flight_pdata p;
	p=malloc(sizeof (flight_data));
	if(p==NULL)
		perror("malloc");
	p=NULL;
	char hnum[18];
	char hnode[18];
	int time;
	while(1)
	{
	p=NULL;
	while(getchar()!='\n');
	menu_search();
	scanf("%d",&data);
	if (data==1)
	{
		printf(CYAN"请输入需要查询的航班号\n"NONE);
		scanf("%s",hnum);
		p=hsearch_flight(hnum,fnode);
		show_search(p);
	}
	if(data==2)
	{
		printf("请输入需要查询的班期\n");
		scanf("%s",hnode);
		p=nsearch_flight(hnode,fnode);
		show_search(p);
	}
	if(data==3)
	{
		printf("请输入需要查询的起飞时间\n");
		scanf("%d",&time);
		p=tsearch_flight(time,fnode);
		show_search(p);
	}
	if(data==4)
		break;
}
}

flight_pdata tsearch_flight(int time,flight_pnode fnode)//起飞时间查询
{
	flight_pdata p;
	p=NULL;
	flight_pnode f=fnode->next;
	while(f!=NULL)
	{
		if(f->flight->stime==time)
		{
			p=f->flight;
			break;
		}
		else
			f=f->next;
	}
    return p;
}


flight_pdata nsearch_flight(char *hnode,flight_pnode fnode)//航班查询
{
	flight_pdata p;
	p=NULL;
	flight_pnode f=fnode->next;
	while(f!=NULL)
	{
		if((strcmp(f->flight->DATE,hnode))==0)
		{
			p=f->flight;
			break;
		}
		else
			f=f->next;
	}
    return p;
}

flight_pdata hsearch_flight(char *hnum,flight_pnode fnode)//班期查询
{
	flight_pdata p;
	p=NULL;
	flight_pnode f=fnode->next;
	while(f!=NULL)
	{
		if((strcmp(f->flight->number,hnum))==0)
		{
			p=f->flight;
			break;
		}
		else
			f=f->next;
	}
    return p;
}

void show_search(flight_pdata p)//输出查询的航班信息
{
	if(p==NULL)
	{
		printf(LIGHT_GREEN"无此航班\n"NONE);
		return;
	}
	else
	{
	printf(HIGH"-----------航班信息-------------------------------------\n"NONE);
	printf("%-8s%-10s%-10s%-10s%-10s%-8s%-8s%-8s\n\n","NO.","S_ADDR","A_ADDR"\
			,"DATE","TYPE","S_TIME","A_TIME","VALUE");
	char at[8];
	char st[8];
		itoa_time(p->atime,at);
		itoa_time(p->stime,st);
		printf("%-8s",p->number);
		printf("%-10s",p->staaddress);
		printf("%-10s",p->arraddress);
		printf("%-10s",p->DATE);
		printf("%-10s",p->TYPE);
		
		printf("%-8s",st);
		printf("%-8s",at);
		printf("%-8d\n\n",p->value);
	}
}
