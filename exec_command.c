#include "main.h"

/**
 * exec_command - check and execute the command
 * @line: input from getline in main
 * @progname: argv[0] from main
 * @envp: env from main
 * Return: nothing
 */

void exec_command(char *line, char *progname, char **envp)
{
	char *args[10];
	char *token;
	int arg_count = 0, allocated = 0;
	pid_t id;

	token = strtok(line, " ");
	while (token)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;
	if (check_path(args[0]))
	{
		args[0] = get_path(envp, args[0]);
		allocated = 1;
	}
	if (args[0] && (command_exists(args[0])))
	{
		id = fork();
	}
	else
	{
		_puts(progname);
		_puts(": No such file or directory\n");
		return;
	}
	if (id == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			free(line);
			//perror(progname);
			_exit(1);
		}
	}
	else
	{
		wait(NULL);
		if (allocated)
		{
			free(args[0]);
		}
	}
}
