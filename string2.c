#include "shell.h"

/**
 * satrcpy - copies a string
 * @dist: input value
 * @sc: input string
 *
 * Return: dist
 */
char *starcpy(char *dist, char *sc)
{
	int j = 0;

	if (dist == sc || sc == 0)
		return (dist);
	while (sc[j])
	{
		dist[j] = sc[j];
		j++;
	}
	dist[j] = 0;
	return (dst);
}

/**
 * starDUP - creates a duplication of a string given
 * @s: string to be duplicated
 *
 * Return: pointer to dup
 */
char *starDUP(const char *s)
{
	int len = 0;
	char *dup;

	if (s == NULL)
		return (NULL);
	while (*s++)
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	for (len++; len--;)
		dup[len] = *--s;
	return (dup);
}

/**
 * PUTS - displays an input string
 *@str: the printed string
 *
 * Return: Nothing
 */

void PUTS(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		Putcher(str[j]);
		j++;
	}
}

/**
 * Putcher - writes a char  to stdout
 * @cc: char to be printed print
 *
 * Return: 1 success -1 failure
 */
int Putcher(char cc)
{
	static int j;
	static char buff[WRITE_BUFF_S];

	if (cc == BUFF_FLUSH || j >= WRITE_BUFF_S)
	{
		write(1, buff, j);
		j = 0;
	}
	if (cc != BUFF_FLUSH)
		buff[j++] = cc;
	return (1);
}
