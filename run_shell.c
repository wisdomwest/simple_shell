#include "shell.h"

// void run_shell() {
//     char *command = NULL;
//     size_t bufsize = 0;
//     ssize_t chars_read;

    
//     int interactive_mode = isatty(STDIN_FILENO);


//     while (1) {

//          if (interactive_mode) {
//             printf("$ ");
//         }
//         chars_read = read_shell(&command, &bufsize, stdin);

//         if (chars_read == -1) {
//             // Error reading line or no characters entered
//             break;
//         }

//         // Tokenize the command into individual arguments
//         char *delimiters = " \t\r\n";
//         char *token = strtok(command, delimiters);
//         char *argv[MAX_ARGUMENTS];
//         int argc = 0;

//         while (token != NULL && argc < MAX_ARGUMENTS - 1) {
//             argv[argc++] = token;
//             token = strtok(NULL, delimiters);
//         }
//         argv[argc] = NULL;

//         // Check for the exit command to terminate the shell
//         if (strcmp(argv[0], "exit") == 0) {
//             break;
//         }

//         // Process the command as needed
//         execute_shell(argv);

//         // Free the allocated memory for each argument
//         for (int i = 0; i < argc; i++) {
//             free(argv[i]);
//         }
//     }

//     // Free the allocated memory for command
//     free(command);
// }



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
