#include "shell.h"

/**
 * refresh - to clear the path list
 * @path_list: path list
 *
 * Return: empty path list
 */

void refresh(char **path_list)
{
	char **empty_list;

	empty_list = malloc(MAX_ARGS * sizeof(char *));
	path_list = empty_list;
	free(empty_list);
	return;
}