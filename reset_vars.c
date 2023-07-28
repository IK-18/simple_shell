#include "shell.h"

/**
 * reset_vars - resets vars in the tokenized string
 * @pseudo: pseudo struct
 *
 * Return: Always 0
 */
int reset_vars(pseudo_t *pseudo)
{
	int i = 0;
	list_t *node;

	for (i = 0; pseudo->argv[i]; i++)
	{
		if (pseudo->argv[i][0] != '$' || !pseudo->argv[i][1])
			continue;

		if (!_strcmp(pseudo->argv[i], "$?"))
		{
			reset_string(&(pseudo->argv[i]),
						 __strdup(__itoa(pseudo->status, 10, 0)));
			continue;
		}
		if (!_strcmp(pseudo->argv[i], "$$"))
		{
			reset_string(&(pseudo->argv[i]),
						 __strdup(__itoa(getpid(), 10, 0)));
			continue;
		}
		node = node_prefix(pseudo->env, &pseudo->argv[i][1], '=');
		if (node)
		{
			reset_string(&(pseudo->argv[i]),
						 __strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		reset_string(&pseudo->argv[i], __strdup(""));
	}
	return (EXIT_SUCCESS);
}