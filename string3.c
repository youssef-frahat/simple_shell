#include "shell.h"

/**
* stringcpy - copies a string
* @dest: input value
* @src: input string
*@n: input integer
* Return: dest
*/
char *stringcpy(char *dest, char *src, int n)
{
	int j, i;
	char *ss = dest;

	j = 0;
	while (src[j] != '\0' && j < n - 1)
	{
		dest[j] = src[j];
		j++;
	}
	if (j < n)
	{
		i = j;
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (ss);
}
/**
* stringcat - concatenate two strings
* @dest: input
* @src: input
* @n: input integer
* Return: dest
*/
char *stringcat(char *dest, char *src, int n)
{
	int j, i;
	char *ss = dest;

	j = 0;
	i = 0;
	while (dest[j] != '\0')
		j++;
	while (src[i] != '\0' && i < n)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	if (i < n)
		dest[j] = '\0';
	return (ss);
}
/**
 * stringchar - locates a character in a string.
 * @ss:  input string
 * @cc:  input char
 *
 * Return: location of charachter or NULL
 */
char *stringchar(char *ss, char cc)
{
	do {
		if (*ss == cc)
			return (ss);
	} while (*ss++ != '\0');

	return (NULL);
}
/**
 * **stringtok - toktenizes a string into words
 * @s: the input string
 * @dl: delimeter of string
 * Return: pointer to an array of strings, or NULL
 */

char **stringtok(char *s, char *dl)
{
	int i, j, k, n, num_words = 0;
	char **str;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!dl)
		dl = " ";
	for (i = 0; s[i] != '\0'; i++)
		if (!isDelim(s[i], dl) && (isDelim(s[i + 1], dl) || !s[i + 1]))
			num_words++;

	if (num_words == 0)
		return (NULL);
	str = malloc((1 + num_words) * sizeof(char *));
	if (!str)
		return (NULL);
	for (i = 0, j = 0; j < num_words; j++)
	{
		while (isDelim(s[i], dl))
			i++;
		for (k = 0; !isDelim(s[i + k], dl) && s[i + k]; )
		{
			k++;
		}
		str[j] = malloc((k + 1) * sizeof(char));
		if (!str[j])
		{
			for (k = 0; k < j; k++)
				free(str[k]);
			free(str);
			return (NULL);
		}
		for (n = 0; n < k; n++)
			str[j][n] = s[i++];
		str[j][n] = 0;
	}
	str[j] = NULL;
	return (str);
}
