#include "shell.h"

/**
* main - mother function that runs the whole process
* argc: argument count
*@argv: argument vector
*@envp: environment vector
*
* Return: int value to indicate success or failure
*/

int main(void)
{
        int fork_val;
	int i;
	char *buf = NULL;
	int flag = 0;
	size_t val;
	char **arg = NULL;
	char **arggs = NULL;
        size_t n = 0;

	while (1)
	{
		write(STDOUT_FILENO, "($)", 3);

		val = getline(&buf, &n, stdin);
		if (val == -1)
		return (-1);

		arg = tokenizer(buf,val,arggs);
		cmd_exec(arg);		
	}

	return (0);
}





/*
* command_check - determine if first token is a valid commaand
*@token: pointer to first token
*
* Return: int value to indicate result
*/
int command_check(char *token)
{
	int flag = 0;
	int i;
	char *list[6] = {"echo","cat","touch", "pwd", "ls", NULL};


	for (i = 0; list[i] != NULL; i++)
	{
		flag = strcmp(token,list[i]);
		if (flag == 0) // check strcmp return val and adjust here
		return (flag);
	}

	return (flag);
}



/*
* tokenizer - converts input string from user into tokens
*@buf: pointer to input string
*@val: length of the input string
*
* Return: char ** pointer to list of tokens
*/
char **tokenizer(char *buf, size_t val, char **arggs)
{
	char *buf_copy;
	char *token;
	int i;
	int token_count = 0;
	char *delim = " ";

	buf_copy = malloc(sizeof(char) * val);
	if (buf_copy == NULL)
	return ((char **) NULL);

	strcpy(buf_copy, buf);
	token = strtok(buf_copy, delim);

	while (token != NULL)
	{
		token = strtok(NULL, delim);
		token_count++;
	}
	token_count++;   
	i = 0;
	while (buf_copy[i] != '\0')
	{
		if (buf_copy[i] == ' ')
		token_count++;
		i++;
	}


	arggs = malloc(sizeof(char *) * token_count);

	token = strtok(buf, delim);
	for (i = 0; token != NULL; i++)
	{
		arggs[i] = malloc(sizeof(char) * strlen(token));
		strcpy(arggs[i], token);
		token = strtok(NULL, delim);
	}
	arggs[i] = NULL;

	return (arggs);

}

/*
int cmd_runner()		
{
		flag = command_check(arggs[0]);

        	if (flag == 0)
            	{
			fork_val = fork();

			if (fork_val == 0)
			execve("ls",args, enp);


			else
			{
				wait(NULL);
				continue;
			}
			
		}

		if (flag == 1)
		{
			errno = ENOENT;
			perror("./shell");
}
 */


