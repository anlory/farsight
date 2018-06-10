#include"../include/flight.h"
void itoa_time(int t,char* str)
{
	char str1[6];
	int len,i;

	sprintf(str1,"%d",t);
		len=strlen(str1);
	for(i=len;i>=len-2;i--)
		str1[i+1]=str1[i];
	str1[i+1]=':';
	strcpy(str,str1);
}


void show(void)
{
	extern flight_pnode fnode;
	printf(BROWN"-----------航班信息-------------------------------------\n"NONE);
	printf(GREEN"%-8s%-10s%-10s%-10s%-10s%-8s%-8s%-8s\n"NONE,"NO.","S_ADDR","A_ADDR"\
			,"DATE","TYPE","S_TIME","A_TIME","VALUE");
	flight_pnode p;
	p=fnode->next;
	while(p != NULL)
	{
		
	char at[8];
	char st[8];
		itoa_time(p->flight->atime,at);
		itoa_time(p->flight->stime,st);
		printf("%-8s",p->flight->number);
		printf("%-10s",p->flight->staaddress);
		printf("%-10s",p->flight->arraddress);
		printf("%-10s",p->flight->DATE);
		printf("%-10s",p->flight->TYPE);
		
		printf("%-8s",st);
		printf("%-8s",at);
		printf("%-8d\n",p->flight->value);
		printf("\n");
		p=p->next;
	}
}
