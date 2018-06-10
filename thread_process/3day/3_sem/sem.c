#include "head.h"

//信号灯的初始化
void init_sem(int semid,int val)
{
      union semun buf;
      buf.val = val;
      if(semctl(semid,0,SETVAL,buf) < 0){
	    perror("semctl");
	    exit(1);
      }
}

//P操作
void sem_p(int semid)
{
      struct sembuf buf = {0,-1,0};
      if(semop(semid,&buf,1) < 0){
	    perror("semop");
	    exit(1);
      }
}
//V操作
void sem_v(int semid)
{
      struct sembuf buf = {0,1,0};
      if(semop(semid,&buf,1) < 0){
	    perror("semop");
	    exit(1);
      }
}
//删除信号灯集合
void del_sem(int semid,int val)
{
      if(semctl(semid,0,IPC_RMID) < 0){
	    perror("semctl");
	    exit(1);
      }
}
