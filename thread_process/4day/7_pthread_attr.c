#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* fun(void* arg)
{
      int i;
      for(i = 0; i < 5; i++){
	    printf("in_fun!\n");
	    sleep(1);
      }
      return (void*)0;
}

int main(void)
{
      int i;
      pthread_t tid;
      pthread_attr_t attr;
      pthread_attr_init(&attr); //初始化线程属性
      pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED); //设置线程分离属性

      if(pthread_create(&tid,&attr,fun,NULL) != 0){
	    perror("pthread_create");
	    exit(1);
      }
#if 0 
      if(pthread_join(tid,NULL) != 0){
	    perror("pthread_join");
	    exit(1);
      }
#endif
      for(i = 0; i < 5; i++){
	    printf("in_main!\n");
	    sleep(1);
      }
      return 0;
}
