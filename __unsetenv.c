#include "shell.h"

/**
 * __unsetenv - unsets an environment variable
 * @pseudo: pseudo struct
 *
 *  Return: 0 on success, 1 otherwise
 */
int __unsetenv(pseudo_t *pseudo)
{
	int i = 1;

	if (pseudo->argc == 1)
	{
		eputs("Too few arguements.\n");
		return (EXIT_FAILURE);
	}
	while (i <= pseudo->argc)
	{
		_unsetenv(pseudo, pseudo->argv[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
