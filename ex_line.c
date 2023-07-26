#include "shell.h"

/**
 * exect_line - finds builtins and commands
 *
 * @datash: data relevant (args)
 * made by Youssef
 * Return: 1 on success.
 */
int exect_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}
