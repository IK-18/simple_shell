#include "shell.h"

/**
 * clear_info - resets pseudo_t struct
 * @pseudo: pseudo struct
 *
 * Return: Nothing
 */
void clear_info(pseudo_t *pseudo)
{
	pseudo->args = NULL;
	pseudo->argv = NULL;
	pseudo->path = NULL;
	pseudo->argc = 0;
}