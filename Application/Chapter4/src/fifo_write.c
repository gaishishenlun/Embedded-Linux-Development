/* fifo_write.c */
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MYFIFO	"/tmp/myfifo"			// 有名管道文件名
#define MAX_BUFFER_SIZE	PIPE_BUF	// 定义在limits.h


int main(int argc, char *argv[]) {

	int fd;
	char buff[MAX_BUFFER_SIZE];
	int nwrite;

	if (argc <= 1) {
		printf("Usage: ./fifo_write string\n");
		exit(1);
	}

	sscanf(argv[1], "%s", buff);
	// 以只写阻塞方式打开FIFO管道
	fd = open(MYFIFO, O_WRONLY);

	if (-1 == fd) {
		printf("Open fifo file error\n");
		exit(1);
	}

	// 向管道中写入字符串
	if ((nwrite = write(fd, buff, MAX_BUFFER_SIZE)) > 0) {
		printf("Write '%s' to FIFO\n", buff);
	}

	close(fd);
	exit(0);
}
