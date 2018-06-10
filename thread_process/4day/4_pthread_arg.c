#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct student{
      int sno;
      char name[20];
      float score;
};

//线程函数
void* fun(void* arg)
{
      struct student *p = (struct student*)arg;
      static int x = 1122;
      //printf("*arg = %d\n",*(int*)arg);
      //printf("arg = %s\n",(char*)arg);
      printf("%d\t%s\t%f\n",p->sno,p->name,p->score);
      return &x;
}

int main(void)
{
      //int i = 123;
      //char str[] = "hello world";
      struct student st = {1001,"小明",98.7};
      pthread_t tid;
      if(pthread_create(&tid,NULL,fun,&st) != 0){
	    perror("pthread_create");
	    exit(1);
      }
      int *px;
      if(pthread_join(tid,(void**)&px) != 0){
	    perror("pthread_join");
	    exit(1);
      }
      printf("*px = %d\n",*px);
      return 0;
}
