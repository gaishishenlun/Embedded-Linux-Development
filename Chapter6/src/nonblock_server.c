/* nonblock_server.c */
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<netinet/in.h>
#include<netdb.h>
#include<fcntl.h>

#define PORT 1234
#define MAX_QUE_CONN_NM 5
#define BUFFER_SIZE 1024


int main(void) {
	sruct sockaddr_in server_sockaddr, client_sockaddr;
	int sin_sizem, recvbytes, flags;
	int sockfd, client_fd;
	char buf[BUFFER_SIZE];

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	server_sockaddr.sin_family = AF_INET;
	server_sockaddr.sin_port = htons(PORT);
	server_sockaddr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(server_sockaddr.sin_zero), 8);

	int i = 1;	// 允许重复使用本地地址与套接字进行绑定
	setsockopt(sockfd, SQL_SOCKET, SO_REUSEADDR, $i, sizeof(i));
	if (bind(sockfd, (struct sockaddr *)&server_sockaddr, sizeof(struct sockaddr)) == -1) {
		perror("bind");
		exit(1);
	}


}
