#include "shell.h"

/**
 * dprint - prints a decimal number (base 10)
 * @in: the input to convert
 * @fd: the file descriptor to write to
 *
 * Return: number of characters printed
 */
int dprint(int in, int fd)
{
	int (*__putchar)(char) = _putchar;
	unsigned int tmp, curr;
	int i = 1000000000, num = 0;

	if (fd == STDERR_FILENO)
		__putchar = eputchar;
	if (in < 0)
	{
		tmp = -in;
		__putchar('-');
		num++;
	}
	else
		tmp = in;
	curr = tmp;
	while (i > 1)
	{
		if (tmp / i)
		{
			__putchar('0' + curr / i);
			num++;
		}
		curr %= i;
		i /= 10;
	}
	__putchar('0' + curr);
	num++;
	return (num);
}