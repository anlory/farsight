#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>


void init_daemon(void)
{
      pid_t pid;
      //第一步：创建一个子进程
      if((pid = fork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid > 0)
	    exit(0);
      //第二步：创建一个会话
      if(setsid() < 0){
	    perror("setsid");
	    exit(1);
      }
      //第三步：忽略SIGHUP信号
      signal(SIGHUP,SIG_IGN);
      //第四步：创建一个子进程
      if((pid = fork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid > 0)
	    exit(0);
      //第五步：关闭所有的文件描述符
      int i,maxfd = sysconf(_SC_OPEN_MAX);
      for(i = 0; i < maxfd; i++)
	    close(i);
      //第六步：消除umask的影响
      umask(0);
      //第七步：更改当前的工作目录
      chdir("/");
      //第八步：重新定位标准IO的文件描述符
      open("dev/null",O_RDWR);
      dup(0);
      dup(0);
}
int main(int argc,char **argv)
{
      int fd;
      char buf[40];
      time_t tm;

      init_daemon();
      if((fd = open("1.txt",O_RDWR|O_CREAT,0644)) < 0){
      }

      while(1){
	    bzero(buf,40);
	    time(&tm);
	    sprintf(buf,"%s",ctime(&tm));
	    write(fd,buf,strlen(buf));
	    sleep(1);
      }
      close(fd);
      return 0;
}

