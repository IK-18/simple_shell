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
	return (write(fd, &c, 1));
}