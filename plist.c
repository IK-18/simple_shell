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

	node = list;
	while (node != NULL)
	{
		_puts(_itoa(node->num, 10, 0));
		_puts(": ");
		_puts(node->str ? node->str : "(nil)");
		_putchar('\n');
		node = node->next;
		n++;
	}
	return (n);
}