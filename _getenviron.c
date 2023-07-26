#include "shell.h"

/**
 * _getenviron - gets a string array copy of the envcpy
 * @pseudo: pseudo struct
 *
 * Return: string array
 */
char **_getenviron(pseudo_t *pseudo)
{
	if (!pseudo->envcpy || pseudo->env_changed)
	{
		pseudo->envcpy = __ltoa(pseudo->env);
		pseudo->env_changed = 0;
	}
	return (pseudo->envcpy);
}
