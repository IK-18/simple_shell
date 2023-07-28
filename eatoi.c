#include "shell.h"

/**
 * eatoi - converts an error string to an integer
 * @str: the string to be converted
 *
 * Return: converted nnumber, 0 if no number, -1 on error
 */
int eatoi(char *str)
{
	int i = 0;
	unsigned long int res = 0;

	if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res *= 10;
			res += (str[i] - '0');
			if (res > INT_MAX)
				return (FLUSH);
		}
		else
			return (FLUSH);
		i++;
	}
	return (res);
}