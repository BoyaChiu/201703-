#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int fd = open("client.c", O_RDONLY);
	if(-1 == fd)
	{
		perror("open client.c");
		return -1;
	}

	int fd1 = open("file.c", O_WRONLY | O_CREAT | O_NOCTTY, 0777);
	if(-1 == fd1)
	{
		perror("open file.c");
		close(fd);
		return -1;
	}

	char buf[256];
	int ret;
	while((ret = read(fd, buf, sizeof(buf))) != 0)
	{
		write(fd1, buf, ret);
	}

	close(fd);
	close(fd1);

	return 0;
}
