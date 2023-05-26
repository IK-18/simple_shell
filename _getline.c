#include "shell.h"

/**
 * _getline - function to store an entire line from input
 * @lineptr: pointer to input buffer
 * @n: size of input buffer
 * @fd: file descriptor
 *
 * Return: number of characters
 */

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	size_t bufsize = *n;
	ssize_t pos = 0;
	int c;

	if (!lineptr || !n)
		return (-1);
	if (!(*lineptr))
	{
		*lineptr = malloc(bufsize);
		if (!(*lineptr))
			return (-1);
	}
	while (1)
	{
		if (read(fd, &c, 1) <= 0)
		{
			if (pos == 0)
				return (-1);
			break;
		}
		if (pos >= bufsize - 1)
		{
			bufsize *= 2;
			char *newptr = (char *)malloc(bufsize);
			if (!newptr)
				return (-1);
			for (int i = 0; i < pos; i++)
				newptr[i] = (*lineptr)[i];
			free(*lineptr);
			*lineptr = newptr;
			*n = bufsize;
		}
		(*lineptr)[pos++] = c;
		if (c == '\n')
			break;
	}
	(*lineptr)[pos] = '\0';
	return (pos);
}
