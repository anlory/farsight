#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 10

int  arr[SIZE];  //静态存储类型
sem_t s1,s2;

void* pthread1(void* arg)
{
      int i;
      for(i = 0; i < SIZE; i++)
	    scanf("%d",&arr[i]);
      sem_post(&s1);
      pthread_exit(0);
}
void* pthread2(void* arg)
{
      int i,j,flag,tmp;
      sem_wait(&s1);
      for(i = 0; i < SIZE-1;i++){
	    flag = 1;
	    for(j = 0; j < SIZE-1-i;j++)
		  if(arr[j] > arr[j+1]){
			tmp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = tmp;
			flag = 0;
		  }
	    if(flag)
		  break;
      }
      sem_post(&s2);
      pthread_exit(0);
}

void* pthread3(void* arg)
{
      int fd,i;
      char buf[BUFSIZ],str[10][10];
      sem_wait(&s2);
      if((fd = open("1.txt",O_WRONLY|O_CREAT|O_TRUNC,0644)) < 0){
	    perror("open");
	    exit(1);
      }
      for(i = 0; i < SIZE;i++)
	    sprintf(str[i],"%d ",arr[i]);
      for(i = 0; i < SIZE;i++)
	    strcat(buf,str[i]);
      write(fd,buf,strlen(buf));
      pthread_exit(0);
}

int main(void)
{
      pthread_t tid[3];

      //对s1,s2初始化
      sem_init(&s1,0,0);
      sem_init(&s2,0,0);

      //创建三个线程
      if(pthread_create(tid,NULL,pthread1,NULL) != 0){
	    perror("pthread_create");
	    exit(1);
      }
      if(pthread_create(tid+1,NULL,pthread2,NULL) != 0){
	    perror("pthread_create");
	    exit(1);
      }
      if(pthread_create(tid+2,NULL,pthread3,NULL) != 0){
	    perror("pthread_create");
	    exit(1);
      }

      if(pthread_join(tid[0],NULL) != 0){
	    perror("pthread_join");
	    exit(1);
      }
      if(pthread_join(tid[1],NULL) != 0){
	    perror("pthread_join");
	    exit(1);
      }
      if(pthread_join(tid[2],NULL) != 0){
	    perror("pthread_join");
	    exit(1);
      }
      return 0;
}
