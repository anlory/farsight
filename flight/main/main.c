#include"../include/flight.h"	
flight_pnode fnode;
int main(void)
{
	int data;
	fnode=init_fnode();
	while(1)
	{
	menu_1();
	scanf("%d",&data);
	if(data==1) //信息录入
		insert();
	if(data==2)//显示信息
		show();
	if(data==3)//查询信息
		search();
	if(data==4)//退出
		break;
}
return 0;
}


 void menu_1(void)
{
	printf(RED"************************************\n"NONE);
	printf("*** 1 信息录入/删除   2信息显示  ***\n");
	printf("*** 3 信息查询        4退出      ***\n");
	printf(BLUE"************************************\n"NONE);
	printf("\n");
}

 void menu_in(void)
{
	printf(YELLOW"*******************************\n"NONE);
	printf("*** 1 信息输入  2 加载信息  ***\n");
	printf("*** 3 信息删除  4 返回      ***\n");
	printf(PURPLE"*******************************\n"NONE);
	printf("\n");
}

void menu_search(void)
{
	printf(GREEN"*******************************\n"NONE);
	printf("** 1 航班查询     2班期查询 ***\n");
	printf("** 3 起飞时间查询 4返回     ***\n");
	printf(LIGHT_GREEN"*******************************\n"NONE);
	printf("\n");
}
