#include "shell.h"

/**
  * run_shell - main loop of shell
  * @c: count
  * @argv: arguments from main
  * Return: void
  */
void exit_code(char *command, int argc);
void run_shell(int c, char **argv, int argc)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t chars_read;
	int interactive_mode = isatty(STDIN_FILENO);

	signal(SIGINT, handle_signal);
	while (1)
	{
		c++;

		if (interactive_mode)
		{
			printf("$ ");
		}

		chars_read = getline(&command, &bufsize, stdin);

		if (chars_read == -1)
		{
			break;
		}

		if (command[chars_read - 1] == '\n')
		{
			command[chars_read - 1] = '\0';
		}

		if (strcmp(command, "exit") == 0)
		{
			exit_code(command, argc);
		}

		execute_shell(command, c, argv);
	}

	free(command);
}

/**
 * exit_code - exit command
 * @code: code
 * @command: commands
 * Return: 0
 */

void exit_code(char *command, int argc)
{
	int n = argc - 1;
        free(command);
        exit(n);
}
