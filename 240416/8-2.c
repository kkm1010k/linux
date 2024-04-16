#include <stdio.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	int status;
	pid = fork();
	if (pid > 0){
		printf("p : waiting\n");
		wait(&status);
		printf("p : status %d\n", status);
	}
	else if (pid == 0){
		sleep(1);
		printf("c : b");
		exit(1234);
	}
	else
		printf("fail");
	printf("bye");
}
