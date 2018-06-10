#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define SIZE 40
int main(void)
{
      int fd[2];
      pid_t pid;

      //创建管道
      if(pipe(fd) < 0){
	    perror("pipe");
	    exit(1);
      }
      printf("pid = %d\n",getpid()); 
      //创建子进程
      if((pid = fork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid > 0){ //父进程 ,从管道读出数据，wc统计单词个数
	    close(fd[1]);
	    dup2(fd[0],STDIN_FILENO);
	    execlp("wc","wc","-w",NULL);
      }else{  //子进程，将ls的结果写入管道
	    close(fd[0]);
	    dup2(fd[1],STDOUT_FILENO);
	    execlp("ls","ls",NULL);
      }
      return 0;
}
