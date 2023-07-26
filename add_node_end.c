#include "shell.h"

/**
 * add_node_end - adds a new node at the end of a list
 * @list: address of the list
 * @str: address of the string to insert into the new node
 * @num: index of node
 *
 * Return: address of the new node
 */
list_t *add_node_end(list_t **list, const char *str, int num)
{
	list_t *temp, *new;

	if (!list)
		return (NULL);
	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	_memset((void *)new, 0, sizeof(list_t));
	new->num = num;
	if (str)
	{
		new->str = __strdup(str);
		if (!new->str)
		{
			free(new);
			return (NULL);
		}
	}
	if (*list)
	{
		for (temp = *list; temp->next; temp = temp->next)
			;
		temp->next = new;
	}
	else
		*list = new;
	return (new);
}