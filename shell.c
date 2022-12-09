/**
* sample shell program
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int fork_val;
	char input[200];
	char *delim = " ";
	char *token;
	char *ptr[];
	char *buf = NULL;
	size_t n = 0;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		getline(&buf, &n, stdin);

		token = strtok(buf, delim);
		

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


  
int twoStrcmp(char a[],char b[])  
{  
	int flag = 0;
	i = 0;  

	while (a[i]!='\0' &&b[i]!='\0')  
	{  
		if (a[i] != b[i])  
		{  
			flag = 1;  
			break;  
		}  
		i++;  
	}
 
	if (a[i]!='\0'||b[i]!='\0')
	return (1);
   
	if (flag == 0)  
	return (0);  
    
	else  
	return (1);  
}

int command_check(char *ptr, char *delim)
{
	char *list[3] = {"cd", "pwd", "ls", NULL};


	for (i = 0; list[i] != '\0'; i++)
	{
		flag = twostrcmp(ptr, list[i];
	}

	return (flag);
}
