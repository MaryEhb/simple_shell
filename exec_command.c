#include "main.h"

/**
 * exec_command - check and execute the command
 * @line: input from getline in main
 * @progname: argv[0] from main
 * @envp: env from main
 * Return: nothing
 */

int exec_command(char *line, char *progname, char **envp)
{
	char *args[1024], *token = strtok(line, " ");
	int arg_count = 0, allocated = 0, status, exit_status = 0;
	pid_t id;

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
		id = fork();
	else
	{
		_errputs(progname);
		_errputs(": 1: ");
		_errputs(args[0]);
		_errputs(": not found\n");
		return (127);
	}
	if (id == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			free(line);
			_exit(1);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
		} else
		{
			_errputs(progname);
			_errputs(": ");
			_errputs(args[0]);
			_errputs(": terminated abnormally\n");
			exit_status = 1;
		}

		if (allocated)
			free(args[0]);
	}
	return (exit_status);
}
