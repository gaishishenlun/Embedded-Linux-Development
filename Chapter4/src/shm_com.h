/* shm_com.h */
#ifndef SHM_COM_H
#define SHM_COM_H

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<signal.h>

#define SHM_BUFFER_SZ 2048

struct shm_buff {
	int pid;
	char buffer[SHM_BUFFER_SZ];
};

#endif
