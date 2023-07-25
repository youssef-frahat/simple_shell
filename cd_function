#include "shell.h"

/**
 * cd_function - changes directory executon env
 * @args: target directory
 *
 * Return: 1 one success, 0 otherwise.
 */
int cd_function(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error in cd_function.c: changing dir\n");
		}
	}
	return (-1);
}
