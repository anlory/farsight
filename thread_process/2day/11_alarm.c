#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
      int i;
      alarm(7);
      for(i = 0; ;i++){
	    printf("i = %d\n",i);
	    sleep(1);
      }
      return 0;
}
