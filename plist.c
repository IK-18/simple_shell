#include "shell.h"

/**
 * plist - prints all elements of a linked list
 * @list: pointer to list
 *
 * Return: number of nodes printed
 */
size_t plist(list_t *list)
{
	size_t n = 0;
	list_t *node;

	for (node = list; node != NULL; node = node->next)
	{
		_puts(__itoa(node->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(node->str ? node->str : "(nil)");
		_putchar('\n');
		n++;
	}
	return (n);
}