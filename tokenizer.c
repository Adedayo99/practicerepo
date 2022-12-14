/**
* tokenizer - function to break string into list of strings
*@buf: pointer to string array
*
* Return: **pointer to list of strings
*/
#include "shell.h"

char **tokenizer(char *buf)
{
	int i;
	char *buf_cpy;
	int len;
	char *token;
	int token_count = 0;
	char *delim = " ";
	char **argv;

	buf_cpy = malloc(sizeof(char) * strlen(buf));
	if (buf_cpy == NULL)
	perror("./shell");
	
	strcpy(buf_cpy, buf);

	token = strtok(buf_cpy, delim);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delim);
	}

	argv = malloc(sizeof(char *) * token_count);

	i = 0;
	token = strtok(buf, delim);
	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;

/*	for (i = 0; argv[i] != NULL; i++)
	printf("%s\n",argv[i]);
*/
	return (argv);

}
