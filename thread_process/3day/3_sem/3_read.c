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
      //创建共享内存
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
      char *p2;
      //将共享内存映射到进程的虚拟空间中
      if( (p2 = shmat(shm_id,NULL,0)) < 0){
	    perror("shmat");
	    exit(1);
      } 
      //从共享内存中读数据
      while(1){
	    //执行P操作,让进阻塞，知道信号灯的值大于0为止
	    sem_p(sem_id);

	    if(strncmp(p2,"quit",4)==0)
		  break;
	    printf("%s",p2);
	    sleep(1);
      }
      //取消映射
      if(shmdt(p2) < 0){
	    perror("shmdt");
	    exit(1);
      }
      return 0;
}
