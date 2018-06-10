#include <stdio.h>
#include <sys/file.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <syslog.h>
#include <signal.h>
int main(int argc,char **argv)
{
      int fd;
      char buf[40] = "helloworld";

      if( (fd = open(argv[1],O_WRONLY)) < 0){
	    perror("open");
	    exit(1);
      }
      if(flock(fd,LOCK_EX) < 0){
	    perror("flock");
	    exit(1);
      }
      while(1){
	    write(fd,buf,strlen(buf));
	    printf("%s\n",buf);
	    sleep(1);
      }
      close(fd);

      return 0;
}

