#include "shell.h"

/**
 * prefix - checks if string starts with character
 * @str: string to search
 * @c: the substring to find
 *
 * Return: address of next char of string or NULL
 */
char *prefix(const char *str, const char *c)
{
	for (; *c; c++)
	{
		if (*c != *str++)
			return (NULL);
	}
	return ((char *)str);
}