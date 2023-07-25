#include "shell.h"

/**
 * reset_alias - resets an alias in the tokenized string
 * @pseudo: pseudo struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int reset_alias(pseudo_t *pseudo)
{
	list_t *node;
	char *c;
	int i = 0;

	while (i < 10)
	{
		node = node_prefix(pseudo->alias, pseudo->argv[0], '=');
		if (node == NULL)
			return (FAILURE);
		free(pseudo->argv[0]);
		c = _strchr(node->str, '=');
		if (c == NULL)
			return (FAILURE);
		c = __strdup(c + 1);
		if (c == NULL)
			return (FAILURE);
		pseudo->argv[0] = c;
		i++;
	}
	return (SUCCESS);
}