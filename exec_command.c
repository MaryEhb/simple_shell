#include "main.h"

/**
 * print_err - print err
 * @progname: prog name
 * @arg: args[0]
 * Return: 127
 */

int print_err(char *progname, char *arg)
{
	_errputs(progname);
	_errputs(": 1: ");
	_errputs(arg);
	_errputs(": not found\n");
	return (127);
}

/**
 * exec_command - check and execute the command
 * @line: input from getline in main
 * @progname: argv[0] from main
 * @envp: env from main
 * Return: ay 7aga
 */

int exec_command(char *line, char *progname, char **envp)
{
	char *args[1024], *token;
	int arg_count = 0, allocated = 0, status, exit_status = 0, i = 0;
	pid_t id;

	while (line[i] == ' ')
		i++;
	if (!line[i])
		return (0);
	token = strtok(&line[i], " ");
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
		return (print_err(progname, args[0]));
	if (id == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			free(line);
			_exit(1);
		}
	} else
	{
		wait(&status);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		if (allocated)
			free(args[0]);
	}
	return (exit_status);
}
