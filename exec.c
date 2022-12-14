/**
* cmd_exec - executed checked command using execve
*@argv: pointer to array of string inputs
*
* Return: Void
*/
#include "shell.h"

void cmd_exec(char **argv)
{

	if ((execve(argv[0], argv, NULL) == -1))
	perror("./shell");

}
