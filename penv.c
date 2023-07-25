#include "shell.h"

/**
 * penv - prints the current environment
 * @pseudo: pseudo struct
 *
 * Return: Always 0
 */
int penv(pseudo_t *pseudo)
{
	plist(pseudo->env);
	return (EXIT_SUCCESS);
}