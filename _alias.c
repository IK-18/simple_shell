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
	list_t *node = NULL;

	if (pseudo->argc == 1)
	{
		node = pseudo->alias;
		for (node; node; node = node->next)
			palias(node);
		return (EXIT_SUCCESS);
	}
	while (pseudo->argv[i])
	{
		c = _strchr(pseudo->argv[i], '=');
		if (c != NULL)
			_setalias(pseudo, pseudo->argv[i]);
		else
		{
			node = node_prefix(pseudo->alias, pseudo->argv[i], '=');
			if (node)
				palias(node_prefix(pseudo->alias, pseudo->argv[i], '='));
		}
		i++;
	}
	return (EXIT_SUCCESS);
}