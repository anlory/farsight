#include "menu.h"

/*子进程负责数据及处理 */
void *fun(void *arg)
{
	system("clear");
	printf("**********************************************\n");
	printf("********        欢迎光临           ***********\n");
	printf("\n");
	printf("********    welcome to my hotel    ***********\n");
	printf("**********************************************\n");
	printf("**********************************************\n");
	sleep(2);
	system("clear");
	
	while(1)
	{
		printf("***********************\n");
		printf("   1:点/加菜 3:催促   \n");
		printf("   2:结帐    4:关闭   \n");
		printf("***     请选择     ***\n");
		printf("**********************\n");
		int input;
		scanf("%d",&input);
		switch(input){
			case 1: order_dish() ;break;
			case 2: pay_bill() ;break;
			case 3: hurry() ;break;
			case 4: shut() ;break;
			default:printf("请输入(1,2,3,4)\n");  break;
		 }
		while(getchar()!='\n');
	}
}




/* 主函数主进程负责通信*/
int main(int argc, char **argv)
{
	sum=0;
	sem_init(&sem,0,0);
	pthread_t tid;
	if(pthread_create(&tid,NULL,fun,NULL) < 0){
		perror("pthread_create");
		exit(1);
	}


	struct sockaddr_in sin;
	//创建套接字
	if( (sock_fd = socket(AF_INET,SOCK_STREAM,0)) < 0){
		perror("socket");
		exit(1);
	}

	//填充地址
	bzero(&sin,sizeof(sin));
	sin.sin_family = AF_INET;
	if(argc != 3){
		sin.sin_port = htons(PORT);
		sin.sin_addr.s_addr = inet_addr(IP);
	}else{
		sin.sin_port = htons(atoi(argv[1]));
		sin.sin_addr.s_addr = inet_addr(argv[2]);
	}
	
	if(connect(sock_fd,( struct sockaddr*)&sin,sizeof(sin)) < 0){
		printf("链接不到服务器,请去前台\n");
	}
	
	//和服务器进行通信
	bufsnd=bufget=malloc(SIZE);
	while (1)
	{
		signal(SIGUSR1,my_func);	
		signal(SIGUSR2,my_func);
		bzero(bufget,SIZE);
		//接收菜谱
		read(sock_fd,bufget,SIZE);
		change_json_array();
		sem_wait(&sem);
		//发送订单
		send_array_json();
	}

	close(sock_fd);
	return 0;
}


