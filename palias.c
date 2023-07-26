#include "shell.h"

/**
 * palias - prints an alias
 * @node: the alias node
 *
 * Return: 0 on success, 1 otherwise
 */
int palias(list_t *node)
{
	char *a = NULL, *b = NULL;

	if (node)
	{
		a = _strchr(node->str, '=');
		b = node->str;
		while (b <= a)
		{
			_putchar(*b);
			b++;
		}
		_putchar('\'');
		_puts(a + 1);
		_puts("'\n");
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}