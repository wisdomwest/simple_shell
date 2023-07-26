#include <stdio.h>
#include "shell.h"

/**
  * main - entry point
  * @argc: argument counter
  * @argv: arguments
  * Return: void
  */

int main(__attribute__((unused)) int argc, char **argv)
{
	int c = 0;

	run_shell(c, argv);
	return (EXIT_SUCCESS);
}
