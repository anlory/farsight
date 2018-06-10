#include "head.h"

int main(int argc,char **argv)
{

      key_t key;
      int sem_id;
      //获得key
      if((key = ftok("./",0xa)) < 0){
	    perror("ftok");
	    exit(1);
      }
      //创建消息队列
      if( (sem_id = semget(key,1,IPC_CREAT|0666)) < 0){
	    perror("semget");
	    exit(1);
      }
      return 0;
}
