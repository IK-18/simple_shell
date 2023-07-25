#include "shell.h"

/**
 * clear_pseudo - resets pseudo_t struct
 * @pseudo: pseudo struct
 *
 * Return: Nothing
 */
void clear_pseudo(pseudo_t *pseudo)
{
	pseudo->args = NULL;
	pseudo->argv = NULL;
	pseudo->path = NULL;
	pseudo->argc = 0;
}