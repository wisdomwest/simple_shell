#include "shell.h"

/**
  * execute_shell - execute command
  * @command: command
  * Return: void
  */

void execute_shell(char *command)
{
	const char *delimiters = " \t\r\n";
	char *arguments[MAX_ARGUMENTS];
	int arg_count = 0;
	int status;
	char *token = strtok(command, delimiters);
	pid_t pid = fork();

	while (token != NULL && arg_count < MAX_ARGUMENTS - 1)
	{
		arguments[arg_count++] = token;
		token = strtok(NULL, delimiters);
	}

	arguments[arg_count] = NULL;

	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		execvp(arguments[0], arguments);
		perror("execvp");
		exit(EXIT_FAILURE);
	}

	else
	{
		waitpid(pid, &status, 0);
	}
}
