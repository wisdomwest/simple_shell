#include "shell.h"

/**
 * _getenv - custom getenv
 * @name: name
 * Return: null or path
 */

char *_getenv(const char *name)
{
	char **j = environ;
	int i = 0;
	int cmp;

	while (j[i] != NULL)
	{
		cmp = strncmp(j[i], name, strlen(name));

		if (cmp == 0)
		{
			return (j[i] + strlen(name) + 1);
		}

		i++;
	}
	return (NULL);
}
