#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* fun(void* arg)
{
      int i;
      static int x = 1122;
      for(i = 0; i < 5; i++){
	    printf("in_fun!\n");
	    sleep(1);
      }
      //return (void*)0;
      pthread_exit(&x);
}

int main(void)
{
      pthread_t tid;
      if(pthread_create(&tid,NULL,fun,NULL) != 0){
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
