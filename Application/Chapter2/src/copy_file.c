/* copy_file.c */
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE			1024					// 缓冲大小
#define SRC_FILE_NAME		"../res/src_file"		// 源文件路径
#define DEST_FILE_NAME	"../res/dest_file"		// 目标文件路径
#define OFFSET					10240					// 复制数据的大小


int main(void) {
	int src_file, dest_file;
	unsigned char buff[BUFFER_SIZE];
	int real_read_len;

	// 只读打开
	src_file = open(SRC_FILE_NAME, O_RDONLY);

	// 只写打开，'0644'等价于'S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH'
	dest_file = open(DEST_FILE_NAME, O_WRONLY, 0644);	

	if (src_file < 0 || dest_file < 0) {
		// 文件标识符为负，文件打开失败。
		printf("Open file error!\n");
		exit(1);
	}

	// 将源文件的读/写指针移到最后10KB的起始位置
	lseek(src_file, -OFFSET, SEEK_END);

	// 读取源文件后10KB数据，并写入到目标文件中，每次读取10KB
	while ((real_read_len = read(src_file, buff, sizeof(buff))) > 0) {
		write(dest_file, buff, real_read_len);
	}

	close(dest_file);
	close(src_file);
	return 0;
}
