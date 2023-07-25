#include "shell.h"

/**
 * _unsetenv - unsets an environment variable
 * @pseudo: pseudo struct
 * @prop: the string env var property
 *
 *  Return: 1 on success, 0 otherwise
 */
int _unsetenv(pseudo_t *pseudo, char *prop)
{
	list_t *node;
	size_t i;
	char *c;

	if (pseudo->env == NULL || prop == NULL)
		return (FAILURE);
	for (i = 0, node = pseudo->env; node; node = node->next, i++)
	{
		c = prefix(node->str, prop);
		if (c != NULL && *c == '=')
		{
			pseudo->env_changed = delete_node_at_index(&(pseudo->env), i);
			i = 0;
			node = pseudo->env;
			continue;
		}
	}
	return (pseudo->env_changed);
}