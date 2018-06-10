#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
      int i;
      alarm(7);
      printf("pid = %d\n",getpid());
      pause();
      return 0;
}
