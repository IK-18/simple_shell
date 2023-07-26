#include "shell.h"

/**
 * _chrdup - duplicates a character in a buffer up to a point
 * @pth: the PATH string
 * @begin: first index
 * @end: last index
 *
 * Return: pointer to new buffer
 */
char *_chrdup(char *pth, int begin, int end)
{
	static char buffer[BUF_SIZE];
	int i = 0, k = 0;

	i = begin;
	while (i < end)
	{
		if (pth[i] != ':')
			buffer[k++] = pth[i];
		i++;
	}
	buffer[k] = 0;
	return (buffer);
}
