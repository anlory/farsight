#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(int argc,char **argv)
{

      key_t key;
      int msg_id;
      //获得key
      if((key = ftok("./",0xa)) < 0){
	    perror("ftok");
	    exit(1);
      }
      //创建消息队列
      if( (msg_id = msgget(key,IPC_CREAT|0666)) < 0){
	    perror("msgget");
	    exit(1);
      }
      return 0;
}
