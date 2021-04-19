/* shm_com.h */
#ifndef _SHM_COM_H
#define _SHM_COM_H

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define DELAY_TIME 3	// 为了突出演示效果，等待几秒

union semun {
	int val;
	struct semid_ds *buf;
	unsigned short *array;
}

#endif
