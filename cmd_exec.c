#include "shell.h"

/**
* cmd_exec - executes input commands
*@arggs: tokenized string input
*
* Return: int value to indicate success
*/

int cmd_exec(char **arggs)
{
	char *cmd = arggs[0];
	

	char cc[] = "/usr/bin/ls";
	execve(cc, arggs, NULL);
	// perror("./shell");

	printf("something is wrong\n");

}
