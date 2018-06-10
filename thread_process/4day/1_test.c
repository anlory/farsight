#include <stdio.h>
#include <unistd.h>

void fun(void)
{
      int i;
      for(i = 0; i < 5; i++){
	    printf("in_fun!\n");
	    sleep(1);
      }
}

int main(void)
{
      int i;
      fun();
      for(i = 0; i < 5; i++){
	    printf("in_main!\n");
	    sleep(1);
      }
      return 0;
}
