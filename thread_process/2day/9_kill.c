#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc,char **argv)
{
      pid_t pid;

      if(argc != 2){
	    fprintf(stderr,"Usage:%s <pid>\n",argv[0]);
	    exit(1);
      }
      pid = atoi(argv[1]);
      //kill(pid,SIGKILL);
      kill(pid,SIGALRM);
      return 0;
}
