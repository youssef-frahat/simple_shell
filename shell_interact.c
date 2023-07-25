#include "shell.h"

/**
 * shell_interact - UNIX command line interpreter
 *
 * Return: void
 */
void shell_interact(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		printf("simple_prompt$ "); /* print prompt symbol */
		line = func_line(); /* read line from stdin */
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
