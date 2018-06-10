#include <stdio.h>
#include <signal.h>

int main(void)
{
      int i;
      for(i = 0; ;i++){
	    printf("i = %d\n",i);
	    if(i == 100)
		  raise(SIGKILL);
      }
      return 0;
}
