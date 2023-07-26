#include "shell.h"

/**
 * handle_signal - handle ^c
 * @signal: signal
 * Return: void
 */

void handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		_write("\n$ ");
	}
}

/**
  * run_shell - main loop of shell
  * @c: count
  * @argv: arguments from main
  * Return: void
  */
 
void run_shell(int c, char **argv) {
  char *command = NULL;
  size_t bufsize = 0;
  ssize_t chars_read;
  int interactive_mode = isatty(STDIN_FILENO);

  char **arguments = argv;

  signal(SIGINT, handle_signal);
  while (1) {
    c++;

    if (interactive_mode) {
      printf("$ ");
    }

    chars_read = getline(&command, &bufsize, stdin);

    if (chars_read == -1) {
      break;
    }

    if (command[chars_read - 1] == '\n') {
      command[chars_read - 1] = '\0';
    }

    if (strcmp(command, "exit") == 0) {
      break;
    }

    // Check if the user entered the `setenv` command
    if (strcmp(command, "setenv") == 0) {
      // Call the custom `_setenv()` function
      int status = _setenv(arguments[1], arguments[2], 1);

      // Check the status of the `_setenv()` function
      if (status != 0) {
        printf("Error setting environment variable: %s\n", arguments[1]);
      }
    } else if (strcmp(command, "unsetenv") == 0) {
      int status = _unsetenv(arguments[1]);

      if (status != 0) {
        printf("Error unsetting environment variable: %s\n", arguments[1]);
      }
    } else {
      execute_shell(command, c, argv);
    }
  }

  free(command);
}
