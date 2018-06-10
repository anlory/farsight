#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

pid_t pid;

void child_fun(int signo)
{
      if(signo == SIGINT){
	    kill(getppid(),SIGUSR1);
      }
      if(signo == SIGQUIT){
	    kill(getppid(),SIGUSR2);
      }
}

void parent_fun(int signo)
{
      if(signo == SIGTSTP){
	    kill(pid,SIGUSR1);	    
      }
}

void move(int signo)
{
      printf("move to next station!\n");
}
void stop(int signo)
{
      printf("stop the bus!\n");
}
void get_off(int signo)
{
      printf("all get off the bus!\n");
}
int main(void)
{

      if((pid = fork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid == 0){ //售票员
	    signal(SIGINT,child_fun); 
	    signal(SIGQUIT,child_fun); 
	    signal(SIGUSR1,get_off); 
	    signal(SIGTSTP,SIG_IGN); 
	    while(1)
		  pause();
      }else{  //司机
	    signal(SIGINT,SIG_IGN); 
	    signal(SIGQUIT,SIG_IGN); 
	    signal(SIGTSTP,parent_fun); 
	    signal(SIGUSR1,move); 
	    signal(SIGUSR2,stop); 
	    while(1)
		  pause();
      }		  
      return 0;
}
