#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	putenv("MYDATA=5");
	printf("%s\n", getenv("MYDATA"));
	execl("5-7-2.c
}
