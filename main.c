#include "main.h"

/**
 * main - Entry point. Simple Shell Project
 * @argc: args count
 * @argv: args array
 * @envp: env array
 * Return: 0 (success)
 */

int main(int argc, char **argv, char **envp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t res = 0;

	(void) argc;

	while (1)
	{
		printf("($) ");
		res = getline(&line, &len, stdin);

		if (res == -1)
		{
			break;
		}

		if (line[res - 1] == '\n')
			line[res - 1] = '\0';

		if ((_strcmp(line, "env")) == 0 || (_strcmp(line, "printenv")) == 0)
		{
			_printenv(envp);
			continue;
		}
		if (line[0] == 'e' && line[1] == 'x' && line[2] == 'i' && line[3] == 't')
			break;
		exec_command(line, argv[0], envp);
	}
	free(line);
	return (0);
}
