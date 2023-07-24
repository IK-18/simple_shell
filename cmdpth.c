#include "shell.h"

/**
 * cmdpth - checks for a command in the PATH string
 * @pseudo: pseudo struct
 * @pth: the PATH string
 * @cmd: the command to find
 *
 * Return: full path of command if found or NULL
 */
char *cmdpth(pseudo_t *pseudo, char *pth, char *cmd)
{
	int i, curr = 0;
	char *str;

	if (pth == NULL)
		return (NULL);
	if ((_strlen(cmd) > 2) && prefix(cmd, "./"))
	{
		if (_iscmd(pseudo, cmd))
			return (cmd);
	}
	for (i = 0; 1; i++)
	{
		if (pth[i] == NULL || pth[i] == ':')
		{
			str = _chrdup(pth, curr, i);
			if (*str == NULL)
				_strcat(str, cmd);
			else
			{
				_strcat(str, "/");
				_strcat(str, cmd);
			}
			if (_iscmd(pseudo, str))
				return (str);
			if (pth[i] == NULL)
				break;
			curr = i + 1;
		}
	}
	return (NULL);
}