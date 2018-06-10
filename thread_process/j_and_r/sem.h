
/* sem_com.h */

#ifndef		SEM_COM_H
#define		SEM_COM_H

#include <sys/ipc.h>
#include <errno.h>
#include <stdio.h>
#include <sys/sem.h>

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};

int init_sem (int sem_id, int nsems,int *);
//int init_sem (int sem_id, int init_value,int index);
int del_sem (int sem_id,int index);
int sem_p (int sem_id,int index);
int sem_v (int sem_id,int index);

#endif							/* SEM_COM_H */
