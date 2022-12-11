#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int command_check(char *token);
int twostrcmp(char a[],char b[]);

int main(int argc, char *argv[], char *envp[])
{
        int fork_val;

	char *delim = " ";
	char *token;
	char *buf = NULL;
	int flag = 0;
	size_t val;
	int exit_val = 1;
	char *args[] = {"ls", NULL};
	char *enp[] = {"PATH=/usr/bin/ls",NULL};
        size_t n = 0;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		val = getline(&buf, &n, stdin);

		token = strtok(buf, delim);
		if (*token == EOF)
		return (0);  

		flag = command_check(token);
        	if (flag == 0)
            	{
			fork_val = fork();

			if (fork_val == 0)
			execve("/bin/ls",args, enp);


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
	char *list[6] = {"echo","cat","touch", "pwd", "ls", NULL};


	for (i = 0; list[i] != NULL; i++)
	{
		flag = twostrcmp(token,list[i]);
		if (flag == 0)
		return (flag);
	}

	return (flag);
}
