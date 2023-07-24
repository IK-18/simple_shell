#include "shell.h"

/**
 * interact - checks if shell is in interactive mode
 * @pseudo: struct address
 *
 * Return: 1 if true, 0 otherwise
 */
int interact(pseudo_t *pseudo)
{
	return (isatty(STDIN_FILENO) && pseudo->readfd <= 2);
}