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
		{"exit", "cause the shell to exit\n", __exit},
		{"env", "prints the current environment\n", penv},
		{"help", "display information about inbuilt commands\n", _help},
		{"history", "display the command history list with line numbers\n", _history},
		{"setenv", "add or change environment variable\n", __setenv},
		{"unsetenv", "remove an environment variable\n", __unsetenv},
		{"cd", "change the working directory\n", _cd},
		{"alias", "define or display aliases\n", _alias},
		{NULL, NULL, NULL}};

	for (i = 0; inbuiltcmds[i].flag; i++)
	{
		tab = (12 - _strlen(inbuiltcmds[i].flag)) / 4;
		ws = (12 - _strlen(inbuiltcmds[i].flag)) % 4;
		if (pseudo->argv[1] != NULL)
		{
			if (_strcmp(pseudo->argv[1], inbuiltcmds[i].flag) == 0)
			{
				_puts(inbuiltcmds[i].flag);
				for (; tab > 0; tab--)
					_putchar('\t');
				for (; ws > 0; ws--)
					_putchar(' ');
				_puts(inbuiltcmds[i].desc);
				return (EXIT_SUCCESS);
			}
			_perror(pseudo, "Not an inbuilt command:\t");
			eputs(pseudo->argv[1]), eputchar('\n');
		}
		else
		{
			_puts(inbuiltcmds[i].flag);
			for (; tab > 0; tab--)
				_putchar('\t');
			for (; ws > 0; ws--)
				_putchar(' ');
			_puts(inbuiltcmds[i].desc);
		}
	}
	return (EXIT_SUCCESS);
}
