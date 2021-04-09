/* multiplex_poll.c */
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<errno.h>
#include<poll.h>

#define MAX_BUFFER_SIZE 1024	// 缓冲区
#define IN_FILES				3			// 多路复用输入文件数目
#define TIME_DELAY			60000 // 超时时间秒数：60s
#define MAX(a, b)				((a > b)?(a):(b))


int main(void) {
	struct pollfd fds[IN_FILES];
	char buf[MAX_BUFFER_SIZE];
	int i, res, real_read, maxfd;

	// 首先按一定的权限打开两个源文件
	fds[0].fd = 0;
	if ((fds[1].fd = open("file1", O_RDONLY|O_NONBLOCK)) < 0) {
		printf("Open file1 error\n");
		return 1;
	}
	if ((fds[2].fd = open("file2", O_RDONLY|O_NONBLOCK)) < 0) {
		printf("Open file2 error\n");
		return 1;
	}

	// 取出两个文件描述符中的较大者
	for (i = 0; i < IN_FILES; i++) {
		fds[i].events = POLLIN;
	}

	// 循环测试是否存在正在监听的文件描述符
	while(fds[0].events || fds[1].events || fds[2].events) {
		if (poll(fds, IN_FILES, 0) < 0) {
			printf("Poll error or Time out\n");
			return 1;
		}
		for (i = 0; i < IN_FILES; i++) {
			if (fds[i].revents) {
				memset(buf, 0, MAX_BUFFER_SIZE);
				real_read = read(fds[i].fd, buf, MAX_BUFFER_SIZE);
				if (real_read < 0) {
					if (errno != EAGAIN) {
						printf("OS error!\n");
						return 1; // 系统错误，结束运行
					}
				}
				else if (!real_read) {
					close(fds[i].fd);
					fds[i].events = 0;	// 取消对文件的监听
				}
				else {
					if (i == 0)	{	// 如果在标准输入上有数据输入时，q或Q退出
						if ((buf[0] == 'q') || (buf[0] == 'Q')) {
							return 1;		
						}
					}
					else {// 将读取的数据先传送到终端上
						buf[real_read] = '\0';
						printf("%s", buf);
					}
				}// end of if real_read
			}// end of if revents
		}// end of for
	}// end of while
	exit(0);
}
