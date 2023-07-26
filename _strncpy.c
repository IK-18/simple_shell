#include "shell.h"

/**
 * *_strncpy - copies a string
 * @dest: pasted string
 * @src: copied string
 * @n: number of bytes to copy
 *
 * Return: pasted string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}
