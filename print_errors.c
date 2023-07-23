#include "shell.h"

/**
 * print_error - errors for shell
 * @in: input
 * @count: counter
 * @argv: arguments from main
 * Return: void
 */

void print_error(char *in, int count, char **argv)
{
	char *n;

	_write(argv[0]);
	_write(": ");
	n = _coun(count);
	_write(n);
	free(n);
	_write(": ");
	_write(in);
	_write(": not found\n");
}
