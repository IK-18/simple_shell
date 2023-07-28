#include "shell.h"

/**
 * _setpseudo - initializes pseudo struct
 * @pseudo: pseudo struct
 * @argv: array of arguments
 *
 * Return: Nothing
 */
void _setpseudo(pseudo_t *pseudo, char *argv[])
{
	int i = 0;

	pseudo->fname = argv[0];
	if (pseudo->args)
	{
		pseudo->argv = _strtok(pseudo->args, " \t");
		if (pseudo->argv == NULL)
		{
			pseudo->argv = malloc(sizeof(char *) * 2);
			if (pseudo->argv)
			{
				pseudo->argv[0] = __strdup(pseudo->args);
				pseudo->argv[1] = NULL;
			}
		}
		while (pseudo->argv && pseudo->argv[i])
			i++;
		pseudo->argc = i;
		reset_alias(pseudo);
		reset_vars(pseudo);
	}
	return;
}
