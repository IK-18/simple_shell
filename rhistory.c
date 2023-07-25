#include "shell.h"

/**
 * rhistory - reads history from file
 * @pseudo: pseudo struct
 *
 * Return: histcount on success, 0 otherwise
 */
int rhistory(pseudo_t *pseudo)
{
	int i = 0, last = 0, count = 0;
	ssize_t fd, bytes_read, fsize = 0;
	struct stat st;
	char *buffer = NULL, *fname = _gethistory(pseudo);

	if (fname == NULL)
		return (EXIT_SUCCESS);
	fd = open(fname, O_RDONLY);
	free(fname);
	if (fd == -1)
		return (EXIT_SUCCESS);
	if (fstat(fd, &st) == 0)
		fsize = st.st_size;
	if (fsize < 2)
		return (EXIT_SUCCESS);
	buffer = malloc(sizeof(char) * (fsize + 1));
	if (buffer == NULL)
		return (EXIT_SUCCESS);
	bytes_read = read(fd, buffer, fsize);
	buffer[fsize] = '\0';
	if (bytes_read == -1)
		return (free(buffer), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			add_history(pseudo, buffer, count++);
			last = i + 1;
		}
	add_history(pseudo, buffer + last, count++);
	free(buffer);
	for (pseudo->histcount = count; pseudo->histcount >= MAX_HISTORY; pseudo->histcount--)
		delete_node_at_index(&(pseudo->history), 0);
	reorder_history(pseudo);
	return (pseudo->histcount);
}