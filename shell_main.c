/**
* shell_main - mother function for simple shell
*@void: no inputs
*
* Return: int value for success
*/
#include "shell.h"

int main(void)
{
	int val, i, fork_val;
	int cmd_status;
	char *buf = NULL;
	size_t n = 0;
	char **argv = NULL;
	char *cmd_path = NULL;

	while (1)
	{
		write(STDOUT_FILENO,"($)", 3);
		val = getline(&buf,&n, stdin);
		buf[val - 1] = ' ';
		
		if (val == -1)
		return (-1);

		i = 0;
		while (buf[i] == ' ')
		{
			buf[i] = '\0';
			i++;
		}
		buf = &buf[i];

		argv = tokenizer(buf);
		cmd_status = cmd_check(argv[0]);

		if (cmd_status == 0)
		{
			fork_val = fork();

			if (fork_val == 0)
			{
				cmd_path = get_path(argv[0]);
				cmd_exec(argv, cmd_path);
			}

			else
			wait(NULL);
		}

/*		else
		{
			errno = 
			perror("./shell");
*/
	}

	return (0);

}


/**
* cmd_check - to check if command is valid
*@token: first token from input
*
* Return: 0 to indicate success
*/

int cmd_check(char *token)
{
	int flag = 1;
	int i = 0;
	char *args[] = {"ls", "touch", "pwd", "rm", "echo", "cat", NULL};

	while (args[i] != NULL)
	{
		flag = strcmp(args[i], token);

		if (flag == 0)
		return (flag);

		i++;
	}

	return (flag);
}
