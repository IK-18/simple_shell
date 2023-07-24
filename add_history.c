#include "shell.h"

/**
 * add_history - adds entry to a history linked list
 * @pseudo: pseudo struct
 * @buffer: buffer
 * @histcount: history linecount
 *
 * Return: Always 0
 */
int add_history(pseudo_t *pseudo, char *buffer, int histcount)
{
	list_t *node = pseudo->history;

	add_node_end(&node, buffer, histcount);
	if (pseudo->history == NULL)
		pseudo->history = node;
	return (EXIT_SUCCESS);
}