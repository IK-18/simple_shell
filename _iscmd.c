#include "shell.h"

/**
 * _iscmd - determines if a file is an executable command
 * @pseudo: pseudo struct
 * @pth: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int _iscmd(pseudo_t *pseudo, char *pth)
{
	struct stat status;

	(void)pseudo;
	if (pth == NULL || stat(pth, &status) != 0)
		return (FAILURE);
	if (status.st_mode & S_IFREG)
		return (SUCCESS);
	return (FAILURE);
}
