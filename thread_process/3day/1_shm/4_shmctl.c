#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc,char **argv)
{
      int shm_id;
      struct shmid_ds s;
      if(argc != 2){
	    fprintf(stderr,"Usage:%s <SHM_ID>\n",argv[0]);
	    exit(1);
      }
      shm_id = atoi(argv[1]);
      //获得共享内存的属性
      if(shmctl(shm_id,IPC_STAT,&s) < 0){
	    perror("shmctl");
	    exit(1);
      }
      //设置共享内存的属性
      if(shmctl(shm_id,IPC_SET,&s) < 0){
	    perror("shmctl");
	    exit(1);
      }
      /*
      //删除共享内存
      if(shmctl(shm_id,IPC_RMID,NULL) < 0){
	    perror("shmctl");
	    exit(1);
      }
      */
     return 0;
}
