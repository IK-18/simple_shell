#include "shell.h"

/**
 * add_node - adds a new node at the beginning of a linked list
 * @list: double pointer to the list
 * @str: new string to add in the node
 * @num: index of node
 *
 * Return: the address of the new list variable, or NULL if it fails
 */
list_t *add_node(list_t **list, const char *str, int num)
{
	list_t *new_node;

	if (list == NULL)
		return (NULL);
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str != NULL)
	{
		new_node->str = _strdup(str);
		if (new_node->str == NULL)
		{
			free(new_node);
			return (NULL);
		}
	}
	new_node->next = *list;
	*list = new_node;
	return (*list);
}