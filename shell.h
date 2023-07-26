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
#include <signal.h>

typedef struct node {
    char *name;
    char *value;
    struct node *next;
} node_t;

extern node_t *head;
extern char **environ;
#define _write(c) (write(STDOUT_FILENO, c, _strlen(c)))
void run_shell(int c, char **argv);
int _strlen(char *s);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void execute_shell(char *command, int c, char **argv);
char *path_of_cmd(char *command);
char *_getenv(const char *name);
void print_error(char *in, int count, char **argv);
char *_coun(unsigned int n);
void handle_signal(int signal);
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

#endif
