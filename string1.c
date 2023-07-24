#include "shell.h"


/**
 * starlens - returns the length of a string
 * @s: string
 * Return: length of a string
 */
int starlens(char *s)
{
	int j = 0;

	if (!s)
		return (0);

	while (*s++)
		j++;
	return (j);
}

/**
* starcmp - compares two string
* @str1: input string 1
* @str2: input string 2
* Return: -1 , 1 or 0
*/
int starcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}


/**
 * str_with - sees if  starts with str
 * @hay: string to be searched
 * @nee: the substring to find
 *
 * Return: pointer to the next char of str or NULL
 */
char *str_with(const char *hay, const char *nee)
{
	while (*nee)
		if (*nee++ != *hay++)
			return (NULL);
	return ((char *)hay);
}

/**
* starcat - concatenates two strings
* @dest: input
* @src: input
*
* Return: pointer to the resulting string dest
*/
char *starcat(char *dest, char *src)
{
	char *r = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (r);
}
