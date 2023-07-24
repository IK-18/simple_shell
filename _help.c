#include "shell.h"

/**
 * _help - provides information on inbuilt commands
 * @pseudo: pseudo struct
 *
 *  Return: Always 0
 */
int _help(pseudo_t *pseudo)
{
	int i, tab, ws;
	inbuilt_cmd inbuiltcmds[] = {
		{"exit", "cause the shell to exit", _exit},
		{"env", "prints the current environment", penv},
		{"help", "display information about inbuilt commands", _help},
		{"history", "display the command history list with line numbers", _history},
		{"setenv", "add or change environment variable", __setenv},
		{"unsetenv", "remove an environment variable", __unsetenv},
		{"cd", "change the working directory", _cd},
		{"alias", "define or display aliases", _alias},
		{NULL, NULL}};

	for (i = 0; inbuiltcmds[i].flag; i++)
	{
		tab = (16 - _strlen(inbuiltcmds[i].flag)) / 4;
		ws = _strlen(inbuiltcmds[i].flag) % 4;
		if (pseudo->argv[1] != NULL)
		{
			if (_strcmp(pseudo->argv[1], inbuiltcmds[i].flag) == 0)
			{
				_puts(inbuiltcmds[i].flag);
				for (tab; tab > 0; tab--)
					_putchar('\t');
				for (ws; ws > 0; ws--)
					_putchar(" ");
				_puts(inbuiltcmds[i].desc);
				return (EXIT_SUCCESS);
			}
			_perror(pseudo, "Not an inbuilt command:\t");
			eputs(pseudo->argv[1]), eputchar("\n");
		}
		else
		{
			_puts(inbuiltcmds[i].flag);
			for (tab; tab > 0; tab--)
				_putchar('\t');
			for (ws; ws > 0; ws--)
				_putchar(" ");
			_puts(inbuiltcmds[i].desc);
		}
	}
	return (EXIT_SUCCESS);
}