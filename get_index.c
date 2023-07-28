#include "shell.h"

/**
 * get_index_at_node - gets the index of a node
 * @list: pointer to list
 * @node: pointer to node
 *
 * Return: index of node or -1
 */
ssize_t get_index_at_node(list_t *list, list_t *node)
{
	list_t *tmp;
	size_t i = 0;

	for (tmp = list; tmp; tmp = tmp->next, i++)
	{
		if (tmp == node)
			return (i);
	}
	return (FLUSH);
}