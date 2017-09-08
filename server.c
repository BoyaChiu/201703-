#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <arpa/inet.h>
#include <string.h>

int main()
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sock)
	{
		perror("socket");
		return -1;
	}

	printf("sock=%d\n",sock);
	struct sockaddr_in s_addr;
	memset(&s_addr, 0, sizeof(s_addr));//清零函数
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(8889);//主机转网络字节序函数
	s_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	int ret = bind(sock, (struct sockaddr *)&s_addr, sizeof(s_addr));
	if(-1 == ret)
	{
		perror("bind");
		close(sock);
		return -1;
	
	}
	
	
	ret = listen(sock, 3);
	if(-1 == ret)
	{
		perror("listen");
		close(sock);
		return -1;
	}
	struct sockaddr_in c_addr;
	memset(&c_addr, 0, sizeof(c_addr));
	socklen_t c_len = sizeof(c_len);
	int rws = accept(sock, (struct sockaddr *)&c_addr, &c_len);
	if(-1 == rws)
	{
	
		perror("accept");
		close(sock);
		return -1;	
	}

	printf("rws=%d\n",rws);
	
	char buf[20] = {0};
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		read(rws,buf,sizeof(buf));
		printf("client:%s\n",buf);
		
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), stdin);
		write(rws, buf, sizeof(buf));
	}
	close(rws);
	close(sock);

	return 0;
}
