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
	char *temp_path;
	struct stat buf;


	keep_path = getenv("PATH");
	
	path = malloc(sizeof(char) * strlen(keep_path));
	strcpy(path, keep_path);
	
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
		int len1;
		int len2;

		len1 = strlen(cmd);
		len2 = strlen(path_list[i]);
		temp_path = malloc(sizeof(char) * (len1 + len2  + 2));
		strcpy(temp_path, path_list[i]);
		strcat(temp_path, "/");
		strcat(temp_path, cmd);
		strcat(temp_path, "\0");


		if (stat(temp_path, &buf) == 0)
		return (temp_path);
	}

	
	return ((char *) NULL);
}
