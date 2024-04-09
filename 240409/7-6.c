#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

	pid_t pid;
	
	printf("h\n");
	
	pid = fork();

	if (pid > 0){
		printf("p\n");
	}
	else if (pid == 0){
		printf("c\n");
		execl("/bin/ls", "ls", "-l", (char *)0);
		printf("f execute");
	}
	else {
		printf("f\n");
	}
	
	printf("b\n");
}
