#include "shell.h"

/**
 * _chrcmp - checks if a character is in a string or array of chars
 * @c: the character to check
 * @str: the string
 *
 * Return: 1 if true, 0 if false
 */
int _chrcmp(char c, char *str)
{
	for (; *str; str++)
	{
		if (*str == c)
			return (SUCCESS);
	}
	return (FAILURE);
}
