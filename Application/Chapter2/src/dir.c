/* dir.c */
#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>


int main(void) {
	DIR *dp;
	struct dirent *entry;

	// 打开目录
	if (NULL == (dp = opendir("."))) {
		perror("opendir");
	}

	// 打印列表头
	printf("%20s%10s%10s%20s\n", "name", "inode", "len", "offset");
	// 循环读取目录项，并打印内容
	while (entry = readdir(dp)) {
		printf("%20s%10ld%10d%30ld\n", entry->d_name, entry->d_ino, entry->d_reclen, entry->d_off);
	}

	// 关闭目录
	closedir(dp);
	return 0;
}
