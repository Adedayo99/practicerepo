/**
* shell_main - mother function for simple shell
*@void: no inputs
*
* Return: int value for success
*/
#include "shell.h"

int main(void)
{
	int val, i;
	int cmd_status;
	char *buf = NULL;
	size_t n = 0;
	char **argv = NULL;


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

		printf("%ld\n", strlen(buf));

		argv = tokenizer(buf);
		cmd_status = cmd_check(argv[0]);

		if (cmd_status == 0)
		get_path(argv[0]);		
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
	char *args[] = {"ls", "touch", "pwd", NULL};

	while (args[i] != NULL)
	{
		flag = strcmp(args[i], token);

		if (flag == 0)
		return (flag);

		i++;
	}

	return (flag);
}
