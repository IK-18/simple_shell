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

	if (list == NULL || *list == NULL)
		return;
	tmp = *list;
	while (tmp != NULL)
	{
		node = tmp->next;
		free(tmp->str);
		free(tmp);
		tmp = node;
	}
	*list = NULL;
}