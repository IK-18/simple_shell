#include "shell.h"

/**
 * get_environ - gets a string array copy of the environ
 * @pseudo: pseudo struct
 *
 * Return: string array
 */
char **get_environ(pseudo_t *pseudo)
{
	if (!pseudo->__imp__environ || pseudo->env_changed)
	{
		pseudo->__imp__environ = ltoa(pseudo->env);
		pseudo->env_changed = 0;
	}
	return (pseudo->__imp__environ);
}