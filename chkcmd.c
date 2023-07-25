#include "shell.h"

/**
 * chkcmd - checks if a command is in PATH
 * @pseudo: pseudo struct
 *
 * Return: Nothing
 */
void chkcmd(pseudo_t *pseudo)
{
	char *path = NULL;
	int i = 0, j = 0;

	pseudo->path = pseudo->argv[0];
	if (pseudo->linecount_flag == 1)
	{
		pseudo->linecount++;
		pseudo->linecount_flag = 0;
	}
	while (pseudo->args[i] != NULL)
	{
		if (!_chrcmp(pseudo->args[i], " \t\n"))
			j++;
		i++;
	}
	if (j == 0)
		return;
	path = cmdpth(pseudo, _getenv(pseudo, "PATH="), pseudo->argv[0]);
	if (path != NULL)
	{
		pseudo->path = path;
		execcmd(pseudo);
	}
	else
	{
		if ((interact(pseudo) || _getenv(pseudo, "PATH=") || pseudo->argv[0][0] == '/') && _iscmd(pseudo, pseudo->argv[0]))
			execcmd(pseudo);
		else if (*(pseudo->args) != '\n')
		{
			pseudo->status = 127;
			_perror(pseudo, "not found\n");
		}
	}
}