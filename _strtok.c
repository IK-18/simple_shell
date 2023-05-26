#include "shell.h"

/**
 * _strtok - splits a string into tikens separated by a delimiter
 * @str: string to be split
 * @delim: delimiter
 *
 * Return: token
 */

char *_strtok(char *str, const char *delim)
{
	static char *s;
	char *token = NULL;

	if (str != NULL)
		s = str;
	if (s != NULL && strlen(s))
	{
		const size_t dlen = strlen(delim);
		while (*s && memchr(delim, *s, dlen) != NULL)
			++s;
		if (*s)
		{
			token = s;
			while (*s)
			{
				if (memchr(delim, *s, dlen) != NULL)
					break;
				++s;
			}
			if (*s)
			{
				s[0] = 0;
				++s;
			}
		}
	}
	return (token);
}
