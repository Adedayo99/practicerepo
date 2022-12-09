/**
* sample shell program
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int fork_val;
	char *buf = NULL;
	size_t n = 0;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		getline(&buf, &n, stdin);
		
		if (*buf != 'q')
		printf("input is: %s", buf);

		else
		break;
	}
/*

	fork_val = fork();
*/
	return (0);	
}
