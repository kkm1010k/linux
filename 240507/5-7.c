#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
int main()
{
	pid_t pid;
	int fd;
	time_t curr;

	if (pid = fork() > 0)
	{
		printf("%d\n",pid);
		exit(0);
	}
	else if (pid == 0)
	{
		setsid();
		while (1)
		{
			curr = time(NULL);
			char *buf = ctime(&curr);
			fd = open("current.txt", O_CREAT | O_RDWR, 0644);
			write(fd, buf, strlen(buf));
			close(fd);
			sleep(10);
		}
	}
}
