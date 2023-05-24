#include "shell.h"

/**
 * _memchr - searches for the first occurrence of a character
 * @s: pointer to memory lock
 * @c: character
 * @n: number of bytes
 *
 * Return: pointer to matching character
 */

void *_memchr(const void *s, int c, size_t n)
{
	const unsigned char *p = s;
	for (size_t i = 0; i < n; i++)
	{
		if (*p == c)
		{
			return (void *)p;
		}
		p++;
	}
	return NULL;
}