#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


int main(int argc,char **argv)
{
      printf("%d\n",geteuid());
      return 0;
}
