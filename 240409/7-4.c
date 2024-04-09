#include <stdio.h>

int main(){
	char *arg[] = {"ls", "-l", {char *}0};
	printf("b\n");
	execv("/bin/ls/",arg);
	printf("a\n");
}
