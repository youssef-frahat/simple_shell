#include "shell.h"

/**
 * exit_fun - process termination routine
 * @args: empty args
 *
 * Return: 0 to terminate the process
 */
int exit_fun(char **args)
{
	/* exit with status */
	if (args[1])
	{
		return (atoi(args[1]));
	}
	/* exit success */
	else
	{
		return (0);
	}
}
