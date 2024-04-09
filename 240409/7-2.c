#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int main()
{
	pid_t pid;
	int i = 0;
	i++;
	
	printf("bcf(%d)\n", i);
	
	pid = fork();

	if (pid == 0){
		printf("cp(%d)\n",++i);
	}
	else if (pid > 0){
		printf("pp(%d)\n", --i);
	}
	else{
		printf("f");
	}
return 0;
}
