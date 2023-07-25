#include "shell.h"

/**
 * _getenviron - gets a string array copy of the environ
 * @pseudo: pseudo struct
 *
 * Return: string array
 */
char **_getenviron(pseudo_t *pseudo)
{
	if (!pseudo->environ || pseudo->env_changed)
	{
		pseudo->environ = ltoa(pseudo->env);
		pseudo->env_changed = 0;
	}
	return (pseudo->environ);
}
