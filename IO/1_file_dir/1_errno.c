#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


int main(int argc,char **argv)
{
      FILE *fp;

      if((fp = fopen("1.txt","r")) == NULL){
	    printf("errno = %d\n",errno);
	    printf("fopen:%s\n",strerror(errno));
	    //perror("fopen");
	    exit(1);
      }
      return 0;
}
