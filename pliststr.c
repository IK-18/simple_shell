#include "shell.h"

/**
 * pliststr - prints all string elements of a linked list
 * @list: pointer to list
 *
 * Return: number of nodes printed
 */
size_t pliststr(const list_t *list)
{
	size_t n = 0;
	list_t *node;

	node = list;
	while (node != NULL)
	{
		_puts(node->str ? node->str : "(nil)");
		_putchar("\n");
		node = node->next;
		n++;
	}
	return (n);
}