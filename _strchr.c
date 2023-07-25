#include "shell.h"

/**
 * _strchr - locates a character in a string
 * @s: string to check
 * @c: character to be found
 *
 * Return: pointer to first occurence of c
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (EXIT_SUCCESS);
}
