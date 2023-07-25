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
	int i, pos = 0;
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
		if (!pth[i] || pth[i] == ':')
		{
			str = _chrdup(pth, pos, i);
			if (!*str)
				_strcat(str, cmd);
			else
			{
				_strcat(str, "/");
				_strcat(str, cmd);
			}
			if (_iscmd(pseudo, str))
				return (str);
			if (!pth[i])
				break;
			pos = i;
		}
	}
	return (NULL);
}