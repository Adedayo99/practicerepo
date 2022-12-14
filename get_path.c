/**
* get_path - function to obtain full path of command
*@token: input command
*
* Return: returns char pointer to full path
*/
#include "shell.h"

char *get_path(char *cmd)
{
	int i;
	char *path;
	char *keep_path;
	char *path_cpy;
	char *token;
	char **path_list;
	int paths = 0;

	keep_path = getenv("PATH");
	
	path = malloc(sizeof(char) * strlen(keep_path));
	strcpy(path, keep_path);

	printf("path printf= %s\n", path);
	
	path_cpy = malloc(sizeof(char) * strlen(path));
	if (path_cpy == NULL) 
	perror("./shell");

	strcpy(path_cpy, path);

	token = strtok(path, ":");
	while (token != NULL)
	{
		paths++;
		token = strtok(NULL, ":");
	}

	path_list = malloc(sizeof(char *) * paths);

	token = strtok(path_cpy, ":");
	i = 0;
	while (token != NULL)
	{
		path_list[i] = malloc(sizeof(char) * strlen(token));
		strcpy(path_list[i], token);
		token = strtok(NULL, ":");
		i++;
	}
	path_list[i] = NULL;

	for (i = 0; path_list[i] != NULL; i++)
	{
		printf("%s\n", path_list[i]);
		free(path_list[i]);
	}
	free(path_list);

	
	return ((char *) NULL);
}
