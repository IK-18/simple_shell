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
	return (write(STDERR_FILENO, &c, 1));
}
