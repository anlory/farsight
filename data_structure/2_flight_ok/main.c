#include "head.h"
#include "linklist.h"

int main(void)
{
	int n,menu;
	char ch;
	char  key[10];
	nodeflight_p h;
	flight_init(&h);

	while(1)
	{
start:
		main_menu();
		printf(BLUE"pls chioce:"NONE);
		scanf("%d",&n);
		switch(n)
		{
start1:
			case 1:
				menu1();
				printf(BLUE"pls chioce:"NONE);
				scanf("%d",&menu);
				switch(menu)
				{
					case 1:
						flight_upload(h);
						printf("信息加载成功,是否返回(Y/N)\n");
						while(getchar() != '\n');
						scanf("%c",&ch);
						goto start1;
					case 2:
						flight_create(h);
						goto start2;
					case 3:
						goto start;
				}
				break;
start2:   		case 2:
				menu2();
				flight_show(h);
				printf(BLUE"pls chioce:"NONE);
				scanf("%d",&menu);
				switch(menu)
				{
					case 1:
t1:						printf("请输入起飞时间:");
						getchar();
						scanf("%s",key);
						flight_search(h,key);
						printf("是否继续(Y/N)？");
						while(getchar() != '\n');
						scanf("%c",&ch);
						if(ch == 'Y' || ch == 'y')
							goto t1;
						else if(ch == 'N' || ch == 'n') 
							goto start2;
					case 2:
						goto start2;
					case 3:
						goto start3;
					case 4:
						goto start;
				}
				break;
start3:			case 3:
				menu3();
				printf(BLUE"pls chioce:"NONE);
				scanf("%d",&menu);
				switch(menu)
				{
					case 1:
						flight_show(h);
						printf("是否返回？(Y/N)");
						while(getchar() !='\n');
						scanf("%c",&ch);
						if((ch == 'Y') || (ch == 'y'))
							goto start3;
					case 2:
						goto start;
				}
				break;
//start4:			
				case 4:
				printf(GREEN LIGHT"Byebye!\n"NONE);
				exit(0);
		}
	}
	return 0;
}
