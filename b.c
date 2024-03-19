#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{	
	char buf[200];
	int fd;
	off_t newpos;
	int cnt = 0;
	if((fd = open(argv[1],O_RDWR))==-1)
	{
		printf("err\n");
		exit(1);
	}

	int len = read(fd,buf,199);
	for(int i = 0;i<len;i++)
	{
		if((int)buf[i] >= 65 && (int)buf[i] <= 122)
		{
			cnt++;
		}

		if((int)buf[i] >= 97 && (int)buf[i] <= 122)
		{
			lseek(fd, (off_t)i, SEEK_SET);
			buf[i] = (int)buf[i] - 32;
			write(fd, &buf[i],1);
		}
	}
	printf("cnt : %d\n", cnt);
	close(fd);
}
