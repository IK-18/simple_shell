#include "shell.h"

/**
 * _memcpy -  copies bytes from one memory block pointed to another
 * @dest: pointer to destination memory lock
 * @src: pointer to source memory lock
 * @n: number of bytes
 *
 * Return: pointer to matching character
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	char *d = dest;
	const char *s = src;
	size_t i;

	for (i = 0; i < n; i++)
		d[i] = s[i];
	return (dest);
}
