

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int command_check(char *token);
int twostrcmp(char a[],char b[]);

int main(void)
{
    //int fork_val;

	char *delim = " ";
	char *token;
	char *buf = NULL;
	int flag = 0;
	size_t val;
	int exit_val = 1;

    size_t n = 0;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		val = getline(&buf, &n, stdin);

		token = strtok(buf, delim);

		exit_val = twostrcmp(token, "exit");
	        if (exit_val == 0)
        	return (0);

	        flag = command_check(token);
        	if (flag == 0)
            	printf("command present\n");

		if (flag == 1)
		printf("command absent\n");


	}

	return (0);
}



int twostrcmp(char a[],char b[])
{
	int flag = 0;
	int i = 0;

	while (a[i] != '\0' && b[i] != '\0')
	{
		if (a[i] != b[i])
		{
			flag = 1;
			return (flag);
		}
		i++;
	}

	return (flag);
}

int command_check(char *token)
{
	int flag = 0;
	int i;
	char *list[4] = {"cd", "pwd", "ls", NULL};


	for (i = 0; list[i] != NULL; i++)
	{
		flag = twostrcmp(token,list[i]);
		if (flag == 0)
		return (flag);
	}

	return (flag);
}
