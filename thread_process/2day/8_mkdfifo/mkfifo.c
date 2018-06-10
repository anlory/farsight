#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char **argv)
{
      if(argc != 2){
	    fprintf(stderr,"Usage:%s <fifoname>\n",argv[0]);
	    exit(1);
      }

      if(mkfifo(argv[1],0644) < 0){
	    perror("mkfifo");
	    exit(1);
      } 
      return 0;
}
