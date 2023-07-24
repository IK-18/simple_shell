#include "shell.h"

/**
 * get_index_at_node - gets the index of a node
 * @list: pointer to list
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_index_at_node(list_t *list, list_t *node)
{
	list_t *tmp;
	size_t i = 0;

	tmp = list;
	while (tmp != NULL)
	{
		if (tmp == node)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}