#include "shell.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of argumets
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv, char **envp)
{
	pseudo_t pseudo[] = {PSEUDO};
	int fd = 2;

	asm("mov %1, %0\n\t"
		"add $3, %0"
		: "=r"(fd)
		: "r"(fd));

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				eputs(argv[0]);
				eputs(": 0: Can't open ");
				eputs(argv[1]);
				eputchar('\n');
				eputchar(FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		pseudo->readfd = fd;
	}
	fill_env(pseudo, envp);
	rhistory(pseudo);
	loop(pseudo, argv);
	return (EXIT_SUCCESS);
}
