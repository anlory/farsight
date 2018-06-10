#include "menu.h"
#define SIZE 2048
#define PORT  8888
#define IP  "192.168.7.100"
/* 菜单服务器*/


sqlite3 *db;
//子进程管理菜谱 订单
void * menu_fun( void *arg)
{

	while(1){

		printf(PURPLE"***************************************\n"NONE);
		printf(PURPLE"*****"NONE);
		printf(RED"1 : 查看菜谱   2 : 管理菜谱  "NONE);
		printf(PURPLE"*****\n"NONE);
		printf(PURPLE"***************************************\n"NONE);
		printf(PURPLE"*****"NONE);
		printf(RED"3 : 查看订单   4 :  营业额   "NONE);
		printf(PURPLE"*****\n"NONE);
		printf(PURPLE"***************************************\n"NONE);
		printf(PURPLE"*****"NONE);
		printf(RED"5 : 退出                     "NONE);
		printf(PURPLE"*****\n"NONE);
		printf(PURPLE"***************************************\n"NONE);
		int input;
		scanf("%d",&input);
		switch(input)
		{
			case 1:show_menu();break;
			case 2:ctl_menu();break;
			case 3:show_bill();break;
			case 4:show_total();break;
			case 5:exit(1);
			default :printf("请正确输入\n");
		}
	}
}

int main(int argc, char **argv)
{
	pthread_t tid;
	if(pthread_create(&tid,NULL,menu_fun,NULL) !=0){
		perror("pthread_create");
		exit(1);
	}
	struct sockaddr_in sin,cin;
	int sock_fd,conn_fd;

	//创建套接字
	if( (sock_fd = socket(AF_INET,SOCK_STREAM,0)) < 0){
		perror("socket");
		exit(1);
	}
	//设置地址可以重用
	int on=1;
	socklen_t leng=sizeof(on);
	if(setsockopt(sock_fd,SOL_SOCKET,SO_REUSEADDR,&on,leng)<0){
		perror("setsocktopt");
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

	//绑定地址
	if(bind(sock_fd,(struct sockaddr*)&sin,sizeof(sin)) < 0){
		perror("bind");
		exit(1);
	}
	//监听套接字
	if(listen(sock_fd,8) < 0){
		perror("listen");
		exit(1);
	}



	//等待接收链接,使进程阻塞，直到有新的客户端请求链接为止
	bzero(&cin,sizeof(cin));
	socklen_t len = sizeof(cin);
	while(1){

		//printf("....\n");

		if( (conn_fd = accept(sock_fd,(struct sockaddr*)&cin,&len)) < 0){
			perror("accept");
			exit(1);
		}
		//和客户端进行通信
		//创建进程和对方交互
		pid_t pid;
		if(( pid= fork()) < 0 ){
			perror("fork");
			exit(1);
		}else if(pid == 0){
			printf("客户%s链接成功!\n",inet_ntoa(cin.sin_addr));
			char *buf;
			char *bufget;
			int total = 0 ;
			bufget=buf=malloc(2048);
			int ret;
			int number= 0;
			while(1){
				//将数据库中数据转化为json
				change_sqlite_json(&buf);
				if(write(conn_fd,buf,strlen(buf))<0){
					perror("write");
					exit(1);
				}
				bzero(bufget,2048);
				if( (ret = read(conn_fd,bufget,2048)) < 0){
					exit(1);
				}else if( ret == 0){
					break;
				}else{
					if(strncmp(bufget,"hurry",5) == 0)
					{
						printf(LIGHT_BLUE"%d号桌发来催促!\n"NONE,number);
						bzero(bufget,200);
					}
					else if(strncmp(bufget,"pay",3) == 0)
					{
						printf(LIGHT_BLUE"%d号桌结帐信息!\n"NONE,number);
						bufget[0]=bufget[1]=bufget[2]='0';
						printf("收款 %d 元\n"NONE,atoi(bufget) );
						total += atoi(bufget);
						//加入total数据表
						total_into( total);

						bzero(bufget,200);
					}
					else
						//获取桌号
						number = get_json_sqlite( bufget,inet_ntoa(cin.sin_addr));
				}}
			close(conn_fd);
			exit(1);
		}
	}

	close(sock_fd);
	return 0;
}
