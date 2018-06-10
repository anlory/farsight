#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>

#define SIZE  100
struct msgbuf{
      long mt;
      char text[SIZE];
};

#endif
