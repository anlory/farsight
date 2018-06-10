/* rose.c */

#include "mylib.h"
#include "sem.h"
#include "print.h"
int sem_id;

char buf_r[BUFSIZ];
char buf_s[BUFSIZ];
/*
union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};
*/
struct message
{
	long msg_type;
	char msg_text[BUFFER_SIZE];
}msgbuf;

//static pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
//static pthread_cond_t v = PTHREAD_COND_INITIALIZER;

/*������Ϣ�߳���*/
void *receiver(void *args)
{
	int qid = *(int *)args;

	while(1){

		//p������ʹ�߳��������ȴ�������Ϣ
		sem_p(sem_id,0);
		Msgrcv(qid, &msgbuf, sizeof(msgbuf), J2R, 0);
		if(strncmp(msgbuf.msg_text,"quit",4) == 0)
			exit(0);
		fprintf(stderr, BLUE"\nform Jack:\n"NONE);
		fprintf(stderr,GREEN"%s\n"NONE, msgbuf.msg_text);
		printf(RED"Rose: \n"NONE);

	}
}
/*������Ϣ�߳���*/
void *sender(void *args)
{
	int qid = *(int *)args;

	while(1){

		printf(RED"Rose: \n"NONE);
		Fgets(buf_s, BUFSIZ, stdin);
		
		strncpy(msgbuf.msg_text, buf_s, strlen(buf_s)+1);
		msgbuf.msg_type = R2J;

		Msgsnd(qid,&msgbuf,strlen(buf_s)+1,0);
		//v�������������Ľ���
		sem_v(sem_id,1);
		if(strncmp(msgbuf.msg_text,"quit",4) == 0)
			exit(0);
	}
}



int main(void)
{
	int qid;
	key_t key1,key2;


	/* create a msg */
	key1 = Ftok(".", 'a');
	key2 = Ftok(".", 'b');

	/*������Ϣ���к��ź�����*/
	qid = Msgget(key1, IPC_CREAT|0666);
	sem_id = semget(key2,2,IPC_CREAT|0666);

	//��ʼ���ź������е������ź���
	int val[2] = {0,0};
	init_sem(sem_id,2,val);

	printf("Open queue %d ",qid);
	printf("(\"quit\" to exit)\n");


	/*
	 ** ���������̣߳��ֱ�����Ϣ�ͽ�����Ϣ
	 */
	pthread_t tid1, tid2;
	Pthread_create(&tid1, NULL, receiver, (void *)&qid);
	Pthread_create(&tid2, NULL, sender, (void *)&qid);

	/***** thread for sending messages *****/
	pause();
	exit(0);
}
