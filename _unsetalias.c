#include "shell.h"

/**
 * _unsetalias - unsets alias
 * @pseudo: psuedo struct
 * @str: string alias
 *
 * Return: 0 on success, 1 on error
 */
int _unsetalias(pseudo_t *pseudo, char *str)
{
	char *s, c;
	int ret;

	s = _strchr(str, '=');
	if (s == NULL)
		return (EXIT_FAILURE);
	c = *s;
	*s = '\0';
	ret = delete_node_at_index(&(pseudo->alias),
							   get_node_at_index(pseudo->alias, node_prefix(pseudo->alias, str, -1)));
	*s = c;
	return (ret);
}