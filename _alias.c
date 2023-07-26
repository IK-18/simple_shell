#include "shell.h"

/**
 * _alias - defines or displays aliases
 * @pseudo: pseudo struct
 *
 *  Return: Always 0
 */
int _alias(pseudo_t *pseudo)
{
	int i = 1;
	char *c = NULL;
	list_t *node;

	if (pseudo->argc == 1)
	{
		for (node = pseudo->alias; node; node = node->next)
			palias(node);
		return (EXIT_SUCCESS);
	}
	while (pseudo->argv[i])
	{
		c = _strchr(pseudo->argv[i], '=');
		if (c)
			_setalias(pseudo, pseudo->argv[i]);
		else
			palias(node_prefix(pseudo->alias, pseudo->argv[i], '='));
		i++;
	}
	return (EXIT_SUCCESS);
}
