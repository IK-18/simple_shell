#include "shell.h"

/**
 * reorder_history - renumbers the history list after changes
 * @pseudo: pseudo struct
 *
 * Return: histcount
 */
int reorder_history(pseudo_t *pseudo)
{
	list_t *node;
	int i;

	for (i = 0, node = pseudo->history; node; node = node->next)
		node->num = i++;
	return (pseudo->histcount = i);
}