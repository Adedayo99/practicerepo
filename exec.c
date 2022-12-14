/**
* cmd_exec - executed checked command using execve
*@argv: pointer to array of string inputs
*
* Return: Void
*/
#include "shell.h"

void cmd_exec(char **argv, char *cmd_path)
{

	if ((execve(cmd_path, argv, NULL) == -1))
	perror("./shell");

}
