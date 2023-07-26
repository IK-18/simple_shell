#include "shell.h"

/**
 * _memset -  fills the first n bytes of the memory block
 * pointed to by s with the constant byte b
 * @s: memory block
 * @b: character to fill in the memory
 * @n: number of bytes to be filled
 *
 * Return: pointer to the memory block s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
