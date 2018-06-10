#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MUTEX

int v1,v2;
pthread_mutex_t m;

void* fun(void* arg)
{
      while(1){
#ifdef MUTEX
	   pthread_mutex_lock(&m);  //给资源上锁
#endif
	    if(v1 != v2)
		  printf("v1 = %d,v2 = %d\n",v1,v2);
#ifdef MUTEX
	   pthread_mutex_unlock(&m);  //给资源上锁
#endif
      }
      return (void*)0;
}

int main(void)
{
      int i;
      pthread_t tid;
      pthread_mutex_init(&m,NULL);

      if(pthread_create(&tid,NULL,fun,NULL) != 0){
	    perror("pthread_create");
	    exit(1);
      }
     for(i = 0; ;i++){ 
#ifdef MUTEX
	   pthread_mutex_lock(&m);  //给资源上锁
#endif
	    v1 = i;
	    v2 = i;
#ifdef MUTEX
	   pthread_mutex_unlock(&m);  //给资源上锁
#endif
      }

      if(pthread_join(tid,NULL) != 0){
	    perror("pthread_join");
	    exit(1);
      }
      return 0;
}
