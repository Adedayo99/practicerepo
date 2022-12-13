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
