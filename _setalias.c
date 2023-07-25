#include "shell.h"

/**
 * _setalias - sets a new alias to string
 * @pseudo: pseudo struct
 * @str: the string alias
 *
 * Return: 0 on success, 1 on error
 */
int _setalias(pseudo_t *pseudo, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (p == 0)
		return (EXIT_FAILURE);
	if (*++p == 0)
		return (_unsetalias(pseudo, str));
	_unsetalias(pseudo, str);
	return (add_node_end(&(pseudo->alias), str, 0) == NULL);
}
