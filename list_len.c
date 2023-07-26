#include "shell.h"

/**
 * list_len - determines the length of a linked list
 * @list: pointer to first node of a list
 *
 * Return: length of list
 */
size_t list_len(const list_t *list)
{
	const list_t *tmp;
	size_t len = 0;

	tmp = list;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}