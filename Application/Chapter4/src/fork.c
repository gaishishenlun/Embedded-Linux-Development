/* fork.c */
#include"sem_com.h"


int main(void) {
	pid_t result;
	int sem_id;

	sem_id = semget(ftok(".", 'a'), 1, 0666|IPC_CREAT);		// 创建一个信号量
	init_sem(sem_id, 0);
	// 调用fork()函数
	result = fork();

	if (result == -1) {
		perror("Fork");
	}
	else if (result == 0) {
		printf("Child process will wait for some seconds...\n");
		sleep(DELAY_TIME);
		printf("The returned value is %d in the child process(PID = %d)\n", result, getpid());
		sem_v(sem_id);
	}
	else {
		sem_p(sem_id);
		printf("The returned value is %d in the father process(PID = %d)\n");
		sem_v(sem_id);
		del_sem(sem_id);
	}
	exit(0);
}
