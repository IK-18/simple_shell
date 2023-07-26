#include "shell.h"

/**
 * eputchar - writes the error character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int eputchar(char c)
{
	static int i;
	static char buf[BUF_SIZE];

	if (c == FLUSH || i >= BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != FLUSH)
		buf[i++] = c;
	return (SUCCESS);
}
