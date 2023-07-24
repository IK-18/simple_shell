#include "shell.h"

/**
 * _strlen - determines the length of a string
 * @s: string
 *
 * Return: length of string
 */
int _strlen(const char *s)
{
	int len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
