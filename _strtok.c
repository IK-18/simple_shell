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
		/*skip consecutive delimiters*/
		while (*s && memchr(delim, *s, dlen) != NULL)
			++s;
		/**
		 * if the beginning of the token is not at the end of the string
		 * set our retval to the first non-delim char
		 */
		if (*s)
		{
			token = s;
			/*search for the next non-delim character, if any*/
			while (*s)
			{
				if (memchr(delim, *s, dlen) != NULL)
					break;
				++s;
			}
			if (*s)
			{
				/*null-terminate the token and march the stored pointer forward*/
				s[0] = 0;
				++s;
			}
		}
	}
	return (token);
}
