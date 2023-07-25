#include "shell.h"

/**
 * non_interact - unix command line interpreter
 *
 * Return: void
 */
void non_interact(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		line = func_stream();
		args = split_line(line); /* tokenize line */
		status = func_exec(args);
		/* avoid memory leaks */
		free(line);
		free(args);
		/* exit with status */
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
