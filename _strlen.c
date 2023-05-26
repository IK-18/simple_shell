#include "shell.h"

/**
 * _strlen - determines the length of a string
 * @s: string
 *
 * Return: length of string
 */

size_t _strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
