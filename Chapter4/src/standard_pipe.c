/* standard_pipe.c */
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

#define BUFFSIZE 1024


int main(void) {

	FILE *fp;
	char *cmd = "ps -ef";
	char buf[BUFFSEZE];

	if ((fp = popen(cmd, "r")) == NULL) {
	// 调用popen()函数执行相应的命令
		printf("Popen error\n");
		exit(1);
	}
	while ((fgets(buf, BUFFSEZE, fp)) != NULL) {
		printf("%s", buf);
	}

	pclose(fp);
	exit(0);
}
