#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char **argv)
{
      pid_t pid;

      if( (pid = fork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid > 0){ //父进程
	    printf("parent:我的父亲是:%d\n",getppid());
	    printf("parent:我是:%d,儿子为%d\n",getpid(),pid);
	    //wait(NULL); //使父进程阻塞，直到有一个子进程结束为止
	    waitpid(pid,NULL,0);
	    exit(0);
      }else{  //子进程
	    printf("我是儿子:%d,父亲的ID为%d\n",getpid(),getppid());
	    exit(0);
      }
}

