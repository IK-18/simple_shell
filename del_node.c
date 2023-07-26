#include "shell.h"

/**
 * delete_node_at_index - deletes a node in a linked list at a certain index
 * @list: pointer to the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, or 0 on fail
 */
int delete_node_at_index(list_t **list, unsigned int index)
{
	list_t *temp, *prev;
	unsigned int i;

	if (!*list || !list)
		return (FAILURE);
	if (index == 0)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp->str);
		free(temp);
		return (SUCCESS);
	}
	for (i = 0, temp = *list; temp; temp = temp->next, i++)
	{
		if (i == index)
		{
			prev->next = temp->next;
			free(temp->str);
			free(temp);
			return (SUCCESS);
		}
		prev = temp;
	}
	return (FAILURE);
}