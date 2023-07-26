#include "shell.h"

/**
 * free_pseudo - frees all fields in struct
 * @pseudo: struct address
 * @all_fields: boolean to free all fields or not
 *
 * Return: Nothing
 */
void free_pseudo(pseudo_t *pseudo, int all_fields)
{
	afree(pseudo->argv);
	pseudo->argv = NULL;
	pseudo->path = NULL;
	if (all_fields)
	{
		if (!pseudo->cmd_buffer)
			free(pseudo->args);
		if (pseudo->env)
			free_list(&(pseudo->env));
		if (pseudo->history)
			free_list(&(pseudo->history));
		if (pseudo->alias)
			free_list(&(pseudo->alias));
		afree(pseudo->environ);
		pseudo->environ = NULL;
		_free((void **)pseudo->cmd_buffer);
		if (pseudo->readfd > 2)
			close(pseudo->readfd);
		_putchar(FLUSH);
	}
}