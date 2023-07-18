#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

void run_shell(void);
void execute_shell(char *argv);
char *path_of_cmd(char *command);

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

#endif
