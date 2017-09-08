#include <stdio.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sock)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in s_addr;
	memset(&s_addr, 0, sizeof(s_addr));
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(8889);
	s_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	int ret = connect(sock, (struct sockaddr *)&s_addr,sizeof(s_addr));
	
	char buf[20];
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf),stdin);
		write(sock, buf, sizeof(buf));
		memset(buf, 0, sizeof(buf));
		read(sock, buf, sizeof(buf));
		printf("server:%s\n",buf);
	}
	close(sock);

	return 0;
}
