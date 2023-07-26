#include "shell.h"

/**
 * __setenv - sets a new environment variable, or modifies an existing one
 * @pseudo: pseudo struct
 *
 *  Return:  0 on success, 1 otherwise
 */
int __setenv(pseudo_t *pseudo)
{
	if (pseudo->argc != 3)
	{
		eputs("Incorrect number of arguements\n");
		return (EXIT_FAILURE);
	}
	if (_setenv(pseudo, pseudo->argv[1], pseudo->argv[2]))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
