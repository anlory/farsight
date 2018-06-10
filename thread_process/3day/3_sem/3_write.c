#include "head.h"

#define SHM_SIZE 1024


int main(int argc,char **argv)
{

      key_t key;
      int shm_id,sem_id;
      //获得key
      if((key = ftok("./",0xa)) < 0){
	    perror("ftok");
	    exit(1);
      }
      //创建/获取共享内存
      if( (shm_id = shmget(key,SHM_SIZE,IPC_CREAT|0666)) < 0){
	    perror("shmget");
	    exit(1);
      }
      //创建信号灯
      if( (sem_id = semget(key,1,IPC_CREAT|0666)) < 0){
	    perror("semget");
	    exit(1);
      }
      //初始化信号灯
      init_sem(sem_id,0);

      char *p1;
      //将共享内存映射到进程的虚拟空间中
      if( (p1 = shmat(shm_id,NULL,0)) < 0){
	    perror("shmat");
	    exit(1);
      } 
      //向共享内存中写数据
      while(1){
	    fgets(p1,SHM_SIZE,stdin);
	    sem_v(sem_id);  //V操作，使信号灯的值加1，唤醒由于p操作阻塞的进程
	    if(strncmp(p1,"quit",4)==0)
		  break;
      }
      //取消映射
      if(shmdt(p1) < 0){
	    perror("shmdt");
	    exit(1);
      }
      return 0;
}
