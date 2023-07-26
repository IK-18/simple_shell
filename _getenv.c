#include "shell.h"

/**
 * _getenv - obtains the value of an env variable
 * @pseudo: pseudo struct
 * @var: env variable name
 *
 * Return: the string value or NULL if var doesn't exist
 */
char *_getenv(pseudo_t *pseudo, const char *var)
{
	list_t *node;
	char *str;

	for (node = pseudo->env; node; node = node->next)
	{
		str = prefix(node->str, var);
		if (*str && str)
			return (str);
	}
	return (NULL);
}
