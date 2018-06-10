
/* sem_com.c */

#include "sem.h"

/*
   函数功能：初始化信号量集
   参数：    sem_id 信号量集id
   参数：	 nsems  信号量的数目
   参数:	 val	信号量集中各个信号量初值数组
 **/
int init_sem (int sem_id, int nsems,int val[])
{
	unsigned short value[nsems],i;
	for(i = 0; i < nsems; i++)
		value[i] = val[i];
	union semun sem_union;
	sem_union.array = value;
	if (semctl (sem_id, 0, SETALL, sem_union) == -1) {
		perror ("Initialize semaphore");
		return -1;
	}
	return 0;
}
/*
int init_sem (int sem_id, int init_value,int index)
{
	union semun sem_union;
	sem_union.val = init_value;
	if (semctl (sem_id, index, SETVAL, sem_union) == -1) {
		perror ("Initialize semaphore");
		return -1;
	}
	return 0;
}
*/
int del_sem (int sem_id,int index)
{
	union semun sem_union;
	if (semctl (sem_id, index, IPC_RMID, sem_union) == -1) {
		perror ("Delete semaphore");
		return -1;
	}

	return 0;
}

int sem_p (int sem_id,int index)
{
	struct sembuf sem_b;
	sem_b.sem_op = -1;			/* P operation */
	sem_b.sem_flg = SEM_UNDO;
	sem_b.sem_num = index;			/*id */

	if (semop (sem_id, &sem_b, 1) == -1) {	/*1:first struct */
		perror ("P operation");
		return -1;
	}
	return 0;
}

int sem_v (int sem_id,int index)
{
	struct sembuf sem_b;

	//sem_b.sem_num = 0;			/* id */
	sem_b.sem_num = index;			/*id */
	sem_b.sem_op = 1;			/* V operation */
	sem_b.sem_flg = SEM_UNDO;	/* It's tracks be follow, to automatical free for it */

	if (semop (sem_id, &sem_b, 1) == -1) {
		perror ("V operation");
		return -1;
	}
	return 0;
}
