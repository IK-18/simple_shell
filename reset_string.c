#include "shell.h"

/**
 * reset_string - sets string to a new value
 * @old_string: old string
 * @new_string: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int reset_string(char **old_string, char *new_string)
{
	free(*old_string);
	*old_string = new_string;
	return (SUCCESS);
}
