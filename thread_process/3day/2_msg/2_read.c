#include "head.h"


int main(int argc,char **argv)
{

      key_t key;
      int msg_id;
      //获得key
      if((key = ftok("./",0xa)) < 0){
	    perror("ftok");
	    exit(1);
      }
      //创建/获取消息队列
      if( (msg_id = msgget(key,IPC_CREAT|0666)) < 0){
	    perror("msgget");
	    exit(1);
      }
      //从消息队列中接收数据
      struct msgbuf buf;
      long type;
      while(1){
	    bzero(&buf,sizeof(buf));
	    printf("请输入要接收的消息类型:");
	    scanf("%ld",&type);
	    if(msgrcv(msg_id,&buf,SIZE,type,0) < 0){
		  perror("msgrcv");
		  exit(1);
	    }
	    printf("%s",buf.text);
      }
      return 0;
}
