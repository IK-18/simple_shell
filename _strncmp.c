#include "shell.h"

/**
 * _strncmp - compares two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes
 *
 * Return: 0 if the same, else the difference of strings
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	int res;

	if (s1 == NULL || s2 == NULL)
		return (EXIT_SUCCESS);
	res = 0;
	while (n > 0 && *s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
		n--;
	}
	if (n > 0)
		res = (*s1 > *s2) - (*s2 > *s1);
	return (res);
}
