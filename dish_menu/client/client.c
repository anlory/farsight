#include "menu.h"
int flag = 0 ;




/*发送订单*/
void send_array_json()
{
	cJSON *food, *bill;
	int i;
	bill = cJSON_CreateObject(); 
	cJSON_AddNumberToObject(bill,"Table",number);
	cJSON_AddItemToObject(bill,"format",food = cJSON_CreateArray());
	for( i = 0; i<mb ;i++){
		cJSON_AddItemToArray(food,cJSON_CreateStringArray(b[i],nb));
	}

	bufsnd= cJSON_Print(bill);
	write(sock_fd,bufsnd,strlen(bufsnd));
}



/*处理催促和结帐信号*/
void my_func(int sign_no)
{
	if(sign_no == SIGUSR1)
	{

		strcpy(bufsnd,"hurry");
		write(sock_fd,bufsnd,strlen(bufsnd));
		usleep(2000);
	}
	if(sign_no == SIGUSR2)
	{
		char buf[5];
		strcpy(bufsnd,"pay");
		sprintf(buf,"%d",sum);
		strcat(bufsnd,buf);
		write(sock_fd,bufsnd,strlen(bufsnd));
		sum = 0;
		flag = 0;
		usleep(2000);

	}
}


/*处理服务器发的json数据*/
void  change_json_array()
{
	int i,j;
	cJSON *food,*root,*c;

	food = cJSON_Parse(bufget);	
	ma=cJSON_GetArraySize(food);
	nb=na=cJSON_GetArraySize(cJSON_GetArrayItem(food,1));
	for(i = 0; i < ma;i++){
		root = cJSON_GetArrayItem(food,i);
		for(j = 0;j < na;j++){
			a[i][j]=(char *) malloc(30);
			c=cJSON_GetArrayItem(root,j);
			a[i][j]=c->valuestring;
		}
	}

}
/*打印订单*/
void show_menu()
{
	int i,j;
	printf("*************************************\n");
	for(i = 0; i < ma; i ++){
		printf("***");
		for(j = 0; j < na;j ++){
			printf("%-18s",a[i][j]);
		}
		printf("***\n");
	}
}

/*点菜*/
void order_dish(void)
{
	//打印菜单
	system("clear");

	show_menu();
	if(flag ==0)
	{
		printf("请输入你的桌号:");
		scanf("%d",&number);
		flag =1 ;
	}
	printf("请输入所点菜的序号和份数(份数最多9份):\n");
	printf("菜和份数之间用 . ,选菜结束输入字符 \nexmple:2.3,2号菜3份 \n");

	float d[30]; 
	int d_i[30],d_f[30];
	int i,j,ret;
	for( i = 0; i < 30; i++)
	{ d[i] = 0.0; d_i[i]=0;d_f[i]=0; }
	i =0;
	while(1)
	{
		ret = scanf("%f",&d[i]);
		if(ret != 1)
			break;
		d_i[i] = (int)d[i];
		d_f[i] = (int)((d[i]-d_i[i] +0.01)*10);
		i++;
	}


	i = 0;
	while(  d_i[i] != 0 ){
		if(d_f[i] == 0) d_f[i] =1;
		if(d_i[i] > 9) {
			i++;
			continue;}
		sprintf( a[d_i[i]][3],"%d", d_f[i]);		
		i ++;
	}


	int k;   k = j = 0;
	for ( i = 1;i < ma;i++)
	{
		if ( atoi(a[i][3]) != 0)	
		{
			for(j =0; j<na; j++)
			{
				b[k][j]=a[i][j];
			}
			k++ ;
			sum += atoi(a[i][2])*atoi(a[i][3]);
		}			
	}
	system("clear");

	mb=k;
	printf("*************************************\n");
	for(i = 0; i <mb ; i ++){
		printf("***");
		for(j = 0; j < nb;j ++){
			printf("%-10s\t",b[i][j]);
		}
		printf("***\n");
	}


	printf("订单合计%d元\n",sum);
	sem_post(&sem);
}

/*结帐*/
void pay_bill(void)
{
	printf("          你好           \n");
	printf("\n         你在本店消费%d元          ",sum);
	printf("          请到前台付款           \n");
	raise(SIGUSR2);
	sleep(2);
}

/*催促*/
void hurry(void)
{
	printf("前台已收到你的催促,请稍等\n");
	printf("不便之处请多多包涵\n");
	raise(SIGUSR1);
}
/*关闭*/
void shut(void)
{
	printf("    欢迎下次光临     \n");
	exit(1);
}
