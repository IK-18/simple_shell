#include "shell.h"

/**
 * fill_env - fills an env linked list
 * @pseudo: pseudo struct
 *
 * Return: Always 0
 */
int fill_env(pseudo_t *pseudo)
{
	size_t i = 0;
	list_t *node = NULL;

	while (environ[i] != NULL)
	{
		add_node_end(&node, environ[i], 0);
		i++;
	}
	pseudo->env = node;
	return (EXIT_SUCCESS);
}