#include "shell.h"

/**
  * run_shell - main loop of shell
  * Return: void
  */

void run_shell()
{
  char *command = NULL;
    size_t bufsize = 0;
    ssize_t chars_read;
    int interactive_mode = isatty(STDIN_FILENO);

    while (1) {
        if (interactive_mode) {
            printf("$ ");
        }

        chars_read = getline(&command, &bufsize, stdin);

        if (chars_read == -1) {
            // Error reading line or no characters entered
            break;
        }

        // Remove the newline character from the command
        if (command[chars_read - 1] == '\n') {
            command[chars_read - 1] = '\0';
        }

        // Check for the exit command to terminate the shell
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Process the command as needed
        execute_shell(command);
    }

    // Free the allocated memory for command
    free(command);
}
