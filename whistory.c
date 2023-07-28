#include "shell.h"

/**
 * whistory - writes to history file
 * @pseudo: pseudo struct
 *
 * Return: 1 on success, -1 otherwise
 */
int whistory(pseudo_t *pseudo)
{
	ssize_t fd;
	char *fname = _gethistory(pseudo);
	list_t *node = NULL;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	if (fname == NULL)
		return (FLUSH);
	fd = open(fname, O_CREAT | O_TRUNC | O_RDWR, mode);
	free(fname);
	if (fd < 0)
		return (FLUSH);
	node = pseudo->history;
	while (node)
	{
		fdputs(node->str, fd);
		fdputchar('\n', fd);
		node = node->next;
	}
	fdputchar(FLUSH, fd);
	close(fd);
	return (SUCCESS);
}