#include "shell.h"

/**
 * _setenv - sets a new environment variable, or modifies an existing one
 * @pseudo: pseudo strut
 * @prop: the env var property string
 * @val: the env var value string
 *
 *  Return: 0 on success, 1 otherwise
 */
int _setenv(pseudo_t *pseudo, char *prop, char *val)
{
	char *c, *buffer = NULL;
	list_t *node;

	if (!prop || !val)
		return (EXIT_SUCCESS);
	buffer = malloc(_strlen(prop) + _strlen(val) + 2);
	if (!buffer)
		return (EXIT_FAILURE);
	_strcpy(buffer, prop);
	_strcat(buffer, "=");
	_strcat(buffer, val);
	node = pseudo->env;
	for (node; node ; node = node->next)
	{
		c = prefix(node->str, prop);
		if (c && *c == '=')
		{
			free(node->str);
			node->str = buffer;
			pseudo->env_changed = 1;
			return (EXIT_SUCCESS);
		}
	}
	add_node_end(&(pseudo->env), buffer, 0);
	free(buffer);
	pseudo->env_changed = 1;
	return (EXIT_SUCCESS);
}
