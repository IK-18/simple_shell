#include "shell.h"

/**
 * afree - frees an array of strings
 * @arr: array of strings
 *
 * Return: Nothing
 */
void afree(char **arr)
{
	char **tmp;

	if (tmp == NULL)
		return;
	for (tmp = arr; *tmp; tmp++)
		free(*tmp);
	free(arr);
}