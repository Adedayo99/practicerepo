#include "shell.h"

/**
* cmd_exec - executes input commands
*@arggs: tokenized string input
*
* Return: int value to indicate success
*/

void cmd_exec(char **arggs)
{	
	char *cmd = NULL;
	cmd = arggs[0];

	if (execve(cmd, arggs, NULL) == -1)
	perror("./shell");

}
