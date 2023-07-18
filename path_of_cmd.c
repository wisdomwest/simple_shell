#include "shell.h"

/**
  * path_of_cmd - path to command
  * @command: command name
  * Return: path or null
  */

char *path_of_cmd(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");
	if (!path)
	{
		printf("Error: PATH environment variable not set.\n");
		return (NULL);
	}
	path_copy = strdup(path);
	command_length = strlen(command);
	path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		directory_length = strlen(path_token);
		file_path = malloc(command_length + directory_length + 2);
		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, command);
		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			path_token = strtok(NULL, ":");
		}
	}
	free(path_copy);
	if (stat(command, &buffer) == 0)
	{
		return (strdup(command));
	}
	return (NULL);
}
