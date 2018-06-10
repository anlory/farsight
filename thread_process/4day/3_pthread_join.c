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
      if(pthread_create(&tid,NULL,fun,NULL) != 0){
	    perror("pthread_create");
	    exit(1);
      }
      
      if(pthread_join(tid,NULL) != 0){
	    perror("pthread_join");
	    exit(1);
      }

      for(i = 0; i < 5; i++){
	    printf("in_main!\n");
	    sleep(1);
      }
      return 0;
}
