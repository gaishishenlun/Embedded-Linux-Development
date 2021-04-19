/* thread_attr.c */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define REPEAT_NUMBER				5			// 线程中的小任务数
#define DELAY_TIME_LEVELS		10.0	// 小任务之间的最大时间间隔
int finish_flag = 0;

void *thrd_func(void *arg) {
// 线程函数例程
	int delay_time = 0;
	int count = 0;

	sleep(1);
	printf("Thread is starting\n");

	for (count = 0; count < REPEAT_NUMBER; count++) {

		delay_time = (int)(rand() * DELAY_TIME_LEVELS/(RAND_MAX)) + 1;
		sleep(delay_time);
		printf("\tThread : job %d delay = %d\n", count, delay_time);
	}

	printf("Thread finished\n");
	finish_flag = 1;
	pthread_exit(NULL);
}


int main(void) {

	pthread_t thread;
	pthread_attr_t attr;
	int res;
	void *thrd_ret;

	srand(time(NULL));
	// 初始化线程属性对象
	res = pthread_attr_init(&attr);

	// 设置线程绑定属性
	res = pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
	//设置线程分离属性
	res += pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	if (res != 0) {
		printf("Setting attribute failed\n");
		exit(res);
	}

	// 创建多线程
	res = pthread_create(&thread, &attr, thrd_func, NULL);

	if (res != 0) {

		printf("Create thread failed\n");
		exit(res);
	}

	pthread_attr_destroy(&attr);
	printf("Create thread success\n");

	while (!finish_flag) {
		printf("Waiting for thread to finish...\n");
		sleep(2);
	}

	return 0;
}
