#include "shell.h"

/**
 * *_strncat - concatenates two strings
 * @dest: string to be appended to
 * @src: string to append
 * @n: number of bytes
 *
 * Return: appended string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
		i++;

	for (j = 0; j < n && src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
