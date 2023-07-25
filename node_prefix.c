#include "shell.h"

/**
 * node_prefix - returns node whose string starts with prefix
 * @list: pointer to list
 * @str: string to match
 * @c: the next character after prefix to match
 *
 * Return: matched node or NULL
 */
list_t *node_prefix(list_t *list, char *str, char c)
{
	char *p = NULL;
	list_t *node;

	for (node = list; node; node = node->next)
	{
		p = prefix(node->str, str);
		if (p && ((c == -1) || (*p == c)))
			return (node);
	}
	return (NULL);
}