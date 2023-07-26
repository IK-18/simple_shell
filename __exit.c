#include "shell.h"

/**
 * __exit - exits the shell
 * @pseudo: pseudo struct
 *
 * Return: an exit status
 */
int __exit(pseudo_t *pseudo)
{
	int chk = -1;

	if (pseudo->argv[1])
	{
		chk = eatoi(pseudo->argv[1]);
		if (chk < 0)
		{
			pseudo->status = 2;
			_perror(pseudo, "Illegal number: ");
			eputs(pseudo->argv[1]);
			eputchar('\n');
			return (EXIT_FAILURE);
		}
		pseudo->err_num = chk;
		return (-2);
	}
	pseudo->err_num = -1;
	return (-2);
}
