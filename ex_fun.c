#include "shell.h"

/**
 * ex_fun - execute arguments
 * @args: command and its flags
 *
 * Return: 1 on sucess, 0 otherwise
 */
int ex_fun(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	int (*builtin_func[])(char **) = {
		&cd_function,
		&env_fun,
		&func_help,
		&exit_fun
	};
	long unsigned int i = 0;

	if (args[0] == NULL)
	{
		/* checking for empty command was entered */
		return (-1);
	}
	/* looking for the command is a builtin */
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		/* if there is a match execute the command */
		if (strcmp(args[0], builtin_func_list[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	/*  new process in proGress.. */
	return (func_process(args));
}