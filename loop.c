#include "shell.h"

/**
 * loop - main shell loop
 * @pseudo: pseudo struct
 * @argv: argument array
 *
 * Return: 0 on success, 1 otherwise, or error code
 */
int loop(pseudo_t *pseudo, char *argv[])
{
	ssize_t i;
	int inbuilt_ret;

	for (i = 0, inbuilt_ret = 0; i != -1 && inbuilt_ret != -2;)
	{
		clear_pseudo(pseudo);
		if (interact(pseudo))
			_puts("$ ");
		eputchar(FLUSH);
		i = _get(pseudo);
		if (i != -1)
		{
			_setpseudo(pseudo, argv);
			inbuilt_ret = execinbuilt(pseudo);
			if (inbuilt_ret == -1)
				chkcmd(pseudo);
		}
		else if (interact(pseudo))
			_puts("\n$ ");
		free_pseudo(pseudo, 0);
	}
	whistory(pseudo);
	free_pseudo(pseudo, 1);
	if (!interact(pseudo) && pseudo->status)
		exit(pseudo->status);
	if (inbuilt_ret == -2)
	{
		if (pseudo->err_num == -1)
			exit(pseudo->status);
		exit(pseudo->err_num);
	}
	return (inbuilt_ret);
}