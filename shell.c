#include "main.h"
char *readline(void);
char **parse(char *line);
int execute(char **args);
int launch(char **args);
void loop(void);

int main(int argc, char **argv)
{
	loop();
	return (EXIT_SUCCESS);
}
void loop(void)
{
    char *line;
    char **args;
    int status;
    do {
        line = readline();
        args = parse(line);
        status = execute(args);
        free(line);
        free(args);
    } while (status);
}
char *readline(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int interactive = isatty(STDIN_FILENO);
	while (1)
	{
		if(interactive)
			printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			break;
		}
	}
	if (nread == -1 && !feof(stdin))
	{
		perror("getline");
		return (NULL);
	}
	return (line);
}
char **parse(char *line)
{
	char *copy = strdup(line);
	char *delim = " \t\r\n\a";
	int count = 0, i = 0;
	char *token = strtok(copy, delim);
	while (token != NULL)
	{
		count++;
		token =strtok(NULL, delim);
	}
	char **words = malloc((count + 1) * sizeof(char *));
	strcpy(copy, line);
	token = strtok(copy, delim);
	while (token != NULL)
	{
		words[i] = strdup(token);/* copy each word */
		i++;
		token = strtok(NULL, delim);
	}
	words[i] = NULL;
	free(copy);
	return (words);
}
int execute(char **args)
{
	if (args[0] == NULL)
	{
		return (1);
	}
	return (launch(args));
}
int launch(char **args)
{
	pid_t child_pid;
	int status;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		execve(args[0], args, NULL);
		return (0);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
