#include "shell.h"

/**
 * _isalpha - Return 1 if it is an alphabet, 0 if not.
 * @c: char type letter
 *
 * Return: 1 if alphabet, 0 if not
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}