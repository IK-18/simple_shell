#include "shell.h"

/**
 * plistnum - prints all num elements of a linked list
 * @list: pointer to list
 *
 * Return: number of nodes printed
 */
size_t plistnum(const list_t *list)
{
	size_t n = 0;
	list_t *node;

	node = list;
	while (node != NULL)
	{
		_puts(_itoa(node->num, 10, 0));
		_putchar("\n");
		node = node->next;
		n++;
	}
	return (n);
}