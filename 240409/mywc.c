#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	pid_t pid[3];
	sleep(2);
	printf("(line) (word) (char)\n");

	for (int i = 0; i < 3; i++){
		pid[i] = fork();
		if (pid[i] == 0){
			execl("/bin/wc", "wc", argv[i+1], (char *)0);
		}
	}
}
