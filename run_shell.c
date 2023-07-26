#include "shell.h"

/**
  * run_exit - exits
  * @command: command
  * @argc: argument counter
  * Return: void
  */

void run_exit(char *command, int argc)
{
	int n = argc - 1;
	
	free(command);
	exit(n);
}

/**
  * run_shell - main loop of shell
  * @c: count
  * @argv: arguments from main
  * Return: void
  */

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
			run_exit(command, argc);
		}

		execute_shell(command, c, argv);
	}

	free(command);
}
