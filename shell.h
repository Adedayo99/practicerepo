#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>

char **tokenizer(char *buf);
int cmd_check(char *token);
void cmd_exec(char **argv, char *cmd_path);
char *get_path(char *cmd);


#endif
