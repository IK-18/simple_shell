#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[BUF_SIZE];

	if (c == FLUSH || i >= BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != FLUSH)
		buf[i++] = c;
	return (SUCCESS);
}
