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
	char *tmp, *suff;
	struct dirent *ent;

	if (dir == NULL)
		return (NULL);
	/*reads directory*/
	ent = readdir(dir);
	while (ent != NULL)
	{
		/*stores name of file in loop and compares*/
		tmp = ent->d_name;
		if (_strcmp(tmp, str))
		{
			suff = _strcat("/bin/", str);
			closedir(dir);
			return (suff);
		}
		ent = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}
