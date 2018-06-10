#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
      chdir("/");
      open("1.txt",O_RDWR|O_CREAT,0644);
      return 0;
}
