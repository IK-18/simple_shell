#include "shell.h"

/**
 * rhistory - reads history from file
 * @pseudo: pseudo struct
 *
 * Return: histcount on success, 0 otherwise
 */
int rhistory(pseudo_t *pseudo)
{
	int i = 0, last_node = 0, count = 0;
	ssize_t fd, bytes_read, fsize = 0;
	struct stat status;
	char *buffer = NULL, *fname = _gethistory(pseudo);

	if (!fname)
		return (FAILURE);
	fd = open(fname, O_RDONLY);
	free(fname);
	if (fd < 0)
		return (FAILURE);
	if (!fstat(fd, &status))
		fsize = status.st_size;
	if (fsize < 2)
		return (FAILURE);
	buffer = malloc(sizeof(char) * (fsize + 1));
	if (!buffer)
		return (FAILURE);
	bytes_read = read(fd, buffer, fsize);
	buffer[fsize] = 0;
	if (bytes_read <= 0)
		return (free(buffer), 0);
	close(fd);
	while (i < fsize)
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = 0;
			add_history(pseudo, buffer + last_node, count++);
			last_node = i + 1;
		}
		i++;
	}
	if (last_node != i)
		add_history(pseudo, buffer + last_node, count++);
	free(buffer);
	for (pseudo->histcount = count; pseudo->histcount >= MAX_HISTORY; pseudo->histcount--)
		delete_node_at_index(&(pseudo->history), 0);
	reorder_history(pseudo);
	return (pseudo->histcount);
}