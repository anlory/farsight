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
      //向消息队列中发送消息
      struct msgbuf buf;
      while(1){
	    bzero(&buf,sizeof(buf));
	    printf("请输入要发送的消息类型:");
	    scanf("%ld",&buf.mt);
	    while(getchar() != '\n');
	    fgets(buf.text,sizeof(buf.text),stdin);
	    if(msgsnd(msg_id,&buf,strlen(buf.text),0) < 0){
		  perror("msgsnd");
		  exit(1);
	    }
      }
      return 0;
}
