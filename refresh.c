#include "shell.h"

/**
 * refresh - to clear the path list
 * @path_list: path list
 *
 * Return: empty path list
 */

char **refresh()
{
	char **empty_list;

	empty_list = malloc(MAX_ARGS * sizeof(char *));
	return (empty_list);
}