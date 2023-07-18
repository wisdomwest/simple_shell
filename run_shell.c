#include "shell.h"

/**
  * run_shell - main loop of shell
  * Return: void
  */

void run_shell(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t chars_read;
	int interactive_mode = isatty(STDIN_FILENO);

	while (1)
	{
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
			break;
		}

		execute_shell(command);
	}

	free(command);
}
