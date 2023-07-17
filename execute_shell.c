#include "shell.h"

void execute_shell(char *command) {
    // Tokenize the command into arguments
    const char *delimiters = " \t\r\n"; // Whitespace delimiters
    char *arguments[MAX_ARGUMENTS];
    int arg_count = 0;
    char *token = strtok(command, delimiters);
    while (token != NULL && arg_count < MAX_ARGUMENTS - 1) {
        arguments[arg_count++] = token;
        token = strtok(NULL, delimiters);
    }
    arguments[arg_count] = NULL; // Set the last argument to NULL for execvp

    // Fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return;
    }

    if (pid == 0) {
        // Child process
        execvp(arguments[0], arguments);
        perror("execvp"); // execvp returns only if an error occurs
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }

}


