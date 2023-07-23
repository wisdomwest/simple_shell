#include "shell.h"

/**
 * _coun - counter
 * @n: number
 * Return: string
 */
char *_coun(unsigned int n)
{
	char *str;
	int i = 0;
	int temp = n;

	do {
		i++;
		temp /= 10;
	} while (temp > 0);

	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}

	str[i] = '\0';

	do {
		i--;
		str[i] = n % 10 + '0';
		n /= 10;
	} while (n > 0);

	return (str);
}
