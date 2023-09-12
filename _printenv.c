#include "main.h"

/**
 * _printenv - print the env
 * @envp: env from main args
 * Return: nothing
 */

void _printenv(char **envp)
{
	int i = 0;

	while (envp[i])
	{
		_puts(envp[i]);
		_putchar('\n');
		i++;
	}
}
