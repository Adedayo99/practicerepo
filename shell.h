#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int command_check(char *token);
int twostrcmp(char a[],char b[]);
char **tokenizer(char *buf, size_t val, char **arggs);
int cmd_exec(char **arggs);




#endif

