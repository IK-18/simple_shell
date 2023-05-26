#include "shell.h"

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: destination file
 * @src: source file
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, const char *src)
{
	char *orig_dest = dest;

	if (dest == NULL || src == NULL)
		return NULL;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (orig_dest);
}