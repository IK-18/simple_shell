#include "shell.h"

/**
 * add_history - adds a node to the history linked list
 * @pseudo: pseudo struct
 * @buffer: buffer
 * @histcount: history linecount
 *
 * Return: Always 0
 */
int add_history(pseudo_t *pseudo, char *buffer, int histcount)
{
	list_t *node = NULL;

	if (pseudo->history)
		node = pseudo->history;
	add_node_end(&node, buffer, histcount);
	if (!pseudo->history)
		pseudo->history = node;
	return (EXIT_SUCCESS);
}