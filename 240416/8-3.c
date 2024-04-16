#include <stdio.h>
#include <unistdh>
#include <sys/types.h>

int main()
{
	pid_t pid1, pid2;
	int status;
	
	pid1 = pid2 = -1;

	pid1 = fork();

	if (pid1 > 0)
		pid2 = fork();
	
	if (pid1 > 0 && pid2 > 0){
		waitpid(pid2, &status, 0);
		printf("p : child2 - exit(%d)\n", status);
		waitpid(pid1, &status, 0);
		printf("p : child1 - exit(%d)\n", status);
	}
}
