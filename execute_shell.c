#include "shell.h"

/**
 * execute_shell - execute command
 * @command: command
 * @c: counter
 * @argv: argument from main
 * Return: void
 */

void execute_shell(char *command, int c, char **argv)
{
	const char *delimiters = " \t\r\n";
	char *arguments[MAX_ARGUMENTS];
	int arg_count = 0;
	const char *path;
	int status;
	char *token = strtok(command, delimiters);
	pid_t pid = fork();

	while (token != NULL && arg_count < MAX_ARGUMENTS - 1)
	{
		arguments[arg_count++] = token;
		token = strtok(NULL, delimiters);
	}

	arguments[arg_count] = NULL;
	path = path_of_cmd(arguments[0]);

	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		
		if (execve(path, arguments, NULL) == -1)
		{
			print_error(arguments[0], c, argv);
			free(command);
			exit(127);
		}
	}

	else
	{
		waitpid(pid, &status, 0);
	}
}
