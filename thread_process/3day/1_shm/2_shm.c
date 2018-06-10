#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
 #include <signal.h>

#define SHM_SIZE 1024

void fun(int signo)
{}

int main(int argc,char **argv)
{

      key_t key;
      int shm_id;
      pid_t pid;
      //获得key
      if((key = ftok("./",0xa)) < 0){
	    perror("ftok");
	    exit(1);
      }
      //创建共享内存
      if( (shm_id = shmget(key,SHM_SIZE,IPC_CREAT|0666)) < 0){
	    perror("shmget");
	    exit(1);
      }
      //用共享内存实现父子进程之间的通信
      if((pid = fork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid > 0){  //父进程,向共享内存中写数据
	    char *p1;
	    //将共享内存映射到父进程的虚拟空间中
	   if( (p1 = shmat(shm_id,NULL,0)) < 0){
		  perror("shmat");
		  exit(1);
	   } 
	   while(1){
		  fgets(p1,SHM_SIZE,stdin);
		  kill(pid,SIGUSR1);
		  if(strncmp(p1,"quit",4)==0)
			break;
	   }
	   //取消映射
	   if(shmdt(p1) < 0){
		  perror("shmdt");
		  exit(1);
	   }
      }else{  //子进程，从共享内存中读数据
	    char *p2;
	    //将共享内存映射到父进程的虚拟空间中
	   if( (p2 = shmat(shm_id,NULL,0)) < 0){
		  perror("shmat");
		  exit(1);
	   } 
	   while(1){
		 signal(SIGUSR1,fun);
		 pause();
		  if(strncmp(p2,"quit",4)==0)
			break;
		 printf("%s",p2);
		 //sleep(1);
	   }
	   //取消映射
	   /*
	   if(shmdt(p2) < 0){
		  perror("shmdt");
		  exit(1);
	   }
      */
      }
      int i;
      for(i = 0; i < 7; i++){
	    printf("i = %d\n",i);
	    sleep(1);
      }
      return 0;
}
