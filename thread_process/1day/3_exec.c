#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc,char **argv)
{
      pid_t pid;

      if( (pid = fork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid > 0){ //父进程
	    printf("我是父亲:%d,儿子的ID为%d\n",getpid(),pid);
	    sleep(1);
	    exit(0);
      }else{  //子进程
#if 0
	    printf("我是儿子:%d,父亲的ID为%d\n",getpid(),getppid());
	    exit(0);

	    //execl("/bin/ls","ls","-l",NULL);
	    char *str[] = {"ls","-l",NULL};
	    execv("/bin/ls",str);
#else
	    execlp("ls","ls","-l",NULL);
#endif
      }
      return 0;
}

