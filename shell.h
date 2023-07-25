#ifndef SHELL_H
#define SHELL_H

/*---LIBRARIES---*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/*---Macros---*/
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/*---PROTOTYPES---*/
/* main.c */
void shell_interact(void);
void non_interact(void);

/* shell_interactive.c */
char *line_fun(void);
char **split_fun(char *line);
int ex_fun(char **args);

/* func_exec */
int process_fun(char **args);

/* shell_no_interactive */
char *stream_fun(void);

/*---Builtin func---*/
int cd_function(char **args);
int exit_fun(char **args);
int env_fun(char **args);
int func_help(char **args);

#endif
