#include "shell.h"

/**
 * reset_vars - resets vars in the tokenized string
 * @pseudo: pseudo struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int reset_vars(pseudo_t *pseudo)
{
	list_t *node;
	int i = 0;

	while (pseudo->argv[i])
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
		if (node != NULL)
		{
			reset_string(&(pseudo->argv[i]),
				__strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		reset_string(&pseudo->argv[i], __strdup(""));
		i++;
	}
	return (EXIT_SUCCESS);
}