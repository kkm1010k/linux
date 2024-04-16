#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	pid_t pid;

	int x;
	int y;
	
	int status;
	
	while (1){
		scanf("%d %d",&x,&y);
		if (x < y && x < 10 && y < 10){
			break;
		}
	}
	pid = fork();
	if (pid > 0){
		int sum = 1;
		for (int i = 0; i<y;i++){
			sum = sum*x;
		}
		wait(&status);
		status = status >> 8;
		printf("%d\n", sum+status);
	}
	else if (pid == 0){
		int sum = 0;
		for (int i = x;i<=y;i++){
			sum += i;
		}
		exit(sum);
	}
}
