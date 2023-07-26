#include <stdio.h>
#include "shell.h"

/**
  * main - entry point
  * @argc: argument counter
  * @argv: arguments
  * Return: void
  */

int main(int argc, char **argv)
{
	int c = 0;

	run_shell(c, argv, argc);
	return (EXIT_SUCCESS);
}
