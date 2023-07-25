#include "shell.h"

/**
 * process_fun - create a new process
 * @args: array that containing the function and flags conditions
 *
 * Return: 1 if success, 0 otherwise.
 */
int process_fun(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid ==  0)
	{
		/* child process */
		if (execvp(args[0], args) == -1)
		{
			perror("error in process_fun: child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* error forking */
		perror("error in process_fun: forking");
	}
	else
	{
		/* parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
