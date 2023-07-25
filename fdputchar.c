#include "shell.h"

/**
 * fdputchar - writes the character c to a given fd
 * @c: character to print
 * @fd: file descriptor
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int fdputchar(char c, int fd)
{
	static int i;
	static char buf[BUF_SIZE];

	if (c == FLUSH || i >= BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != FLUSH)
		buf[i++] = c;
	return (1);
}