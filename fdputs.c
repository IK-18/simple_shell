#include "shell.h"

/**
 *fdputs - prints an input string to a file descriptor
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of chars put
 */
int fdputs(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (EXIT_SUCCESS);
	for (; *str; str++)
		i += fdputchar(*str, fd);
	return (i);
}
