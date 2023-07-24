#include "shell.h"

/**
 * reorder_history - renumbers the history list after changes
 * @pseudo: pseudo struct
 *
 * Return: histcount
 */
int reorder_history(pseudo_t *pseudo)
{
	list_t *node = pseudo->history;
	int i;

	for (i = 0, node; node; node = node->next, i++)
		node->num = i;
	return (pseudo->histcount = i);
}