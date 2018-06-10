#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <signal.h>

union semun {
      int              val;    /* Value for SETVAL */
      struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
      unsigned short  *array;  /* Array for GETALL, SETALL */
      struct seminfo  *__buf;  /* Buffer for IPC_INFO
				  (Linux-specific) */
};

extern void init_sem(int semid,int val);
extern void sem_p(int semid);
extern void sem_v(int semid);
extern void del_sem(int semid,int val);
#endif
