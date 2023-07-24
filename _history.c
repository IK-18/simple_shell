#include "shell.h"

/**
 * _history - displays the history list
 * @pseudo: pseudo struct
 *
 * Return: Always 0
 */
int _history(pseudo_t *pseudo)
{
	plist(pseudo->history);
	return (EXIT_SUCCESS);
}