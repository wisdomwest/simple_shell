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

// Function prototypes
void run_shell(void);
// ssize_t read_shell(char **lineptr, size_t *n, FILE *stream);
// void parse_shell();
// void execute_shell(char *command);
void execute_shell(char *argv);
char *path_of_cmd(char *command);
void print_prompt();



// void execute_command(char *command);

// Constants
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64


#endif 
