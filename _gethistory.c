#include "shell.h"

/**
 * _gethistory - gets the history file
 * @pseudo: pseudo struct
 *
 * Return: history file or NULL
 */
char *_gethistory(pseudo_t *pseudo)
{
	char *buffer, *dir;

	dir = _getenv(pseudo, "HOME=");
	if (dir == NULL)
		return (NULL);
	buffer = malloc(sizeof(char) * (_strlen(dir) + _strlen(HISTORY) + 2));
	if (buffer == NULL)
		return (NULL);
	buffer[0] = 0;
	_strcpy(buffer, dir);
	_strcat(buffer, "/");
	_strcat(buffer, HISTORY);
	return (buffer);
}
