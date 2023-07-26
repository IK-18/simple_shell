#include "shell.h"

/**
 * free_list - frees a linked list
 * @list: list to be freed
 *
 * Return: Nothing
 */
void free_list(list_t **list)
{
	list_t *tmp, *node;

	if (!*list || list)
		return;
	for (tmp = *list; tmp; tmp = node)
	{
		node = tmp->next;
		free(tmp->str);
		free(tmp);
	}
	*list = NULL;
}