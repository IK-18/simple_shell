#include "shell.h"

/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: pointer to the malloc
 * @old_size: current size of pointer.
 * @new_size: size of new memory block.
 *
 * Return: pointer to new memory block or NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *nptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (!new_size && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		nptr = malloc(new_size);
		if (!nptr)
			return (NULL);
	}
	if (new_size > old_size && ptr)
	{
		nptr = malloc(new_size);
		if (!nptr)
			return (nptr);
		for (i = 0; i < old_size; i++)
			nptr[i] = *((char *)ptr + 1);
		free(ptr);
	}
	return (nptr);
}
