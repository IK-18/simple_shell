#include "shell.h"

/**
 *
 *
 */

int main(int argc, char **argv, char **environ)
{
    if (argc == 1)
        prompt(argv, environ);
    return (0);
}