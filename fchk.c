#include "shell.h"

/**
 * fchk - checks if a command exists to avoid fork caalling
 * @str: string to check
 *
 * Return: Appended path if it exists, NULL if it doesn't
 */

char *fchk(char *str)
{
	DIR *dir = opendir("/bin/");
	char *tmp, *suff, bin[50] = "/bin/";
	struct dirent *ent;

	if (dir == NULL)
		return (NULL);
	/*reads directory*/
	while ((ent = readdir(dir)) != NULL)
	{
		/*stores name of file in loop and compares*/
		tmp = ent->d_name;
		_puts(tmp);
		_puts("\n");
		if (_strcmp(tmp, str) == 0)
		{
			suff = _strcat(bin, str);
			_puts(suff);
			closedir(dir);
			return (suff);
		}
	}
	closedir(dir);
	return (NULL);
}
