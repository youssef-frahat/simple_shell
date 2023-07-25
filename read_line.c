#include "shell.h"

/**
 * r_lin - reads the input string.
 *
 * @i_eof: return value of getline function
 * made by hassan and youssef
 * Return: input string
 */
char *r_lin(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
