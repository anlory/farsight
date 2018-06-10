#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_fun(int signo)
{
      printf("hello world\n");
}

int main(void)
{
      int i;
      signal(SIGALRM,sig_fun);
      alarm(7);
      for(i = 0; ;i++){
	    printf("i = %d\n",i);
	    sleep(1);
      }
      return 0;
}
