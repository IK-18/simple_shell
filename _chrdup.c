#include "shell.h"

/**
 * _chrdup - duplicates a character in a buffer up to a point
 * @pth: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *_chrdup(char *pth, int start, int stop)
{
	static char buffer[1024];
	int i = 0, k = 0;

	i = start;
	while (i < stop)
	{
		if (pth[i] != ':')
			buffer[k++] = pth[i];
		i++;
	}
	buffer[k] = 0;
	return (buffer);
}