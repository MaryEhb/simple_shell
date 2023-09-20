#include "main.h"

/**
 * print_err - print err
 * @progname: prog name
 * @arg: args[0]
 * @msg: message
 *
 * Return: 127
 */
int print_err(char *progname, char *arg, char *msg)
{
	_errputs(progname);
	_errputs(": 1: ");
	_errputs(arg);
	_errputs(": ");
	_errputs(msg);
	return (127);
}
/**
 * ignore_space - ignores spaces
 * @line: line
 * @i: index
 * Return: char
 */
char ignore_space(char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
	return (line[*i]);
}

/**
 * exec_command - check and execute the command
 * @line: input from getline in main
 * @progname: argv[0] from main
 * @envp: env from main
 * @exit_status: exit
 *
 * Return: ay 7aga
 */
int exec_command(char *line, char *progname, char **envp, int exit_status)
{
	char *args[1024], *token;
	int arg_count = 0, allocated = 0, status, i = 0;
	pid_t id;

	if (!ignore_space(line, &i))
		return (0);
	token = strtok(&line[i], " ");
	while (token)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;
	func(progname, args, arg_count, line, exit_status);
	if (check_path(args[0]))
	{
		args[0] = get_path(envp, args[0]);
		allocated = 1;
	}
	if (args[0] && (command_exists(args[0])))
		id = fork();
	else
		return (exit_status = (print_err(progname, args[0], "not found\n")));
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

/**
 * func - asdlkfjla
 * @progname: name
 * @args: arguments
 * @arg_count: args count
 * @line: line
 * @e: exit
 *
 * Return: Nothing
 */
void func(char *progname, char **args, int arg_count, char *line, int e)
{
	int exit_arg = 0;

	if (!_strcmp(args[0], "exit"))
	{
		if (arg_count == 1)
		{
			free(line);
			_exit(e);
		}

		exit_arg = _errtoi(args[1]);
		if (exit_arg == -1)
		{
			print_err(progname, args[0], "Illegal number: ");
			_errputs(args[1]);
			_errputchar('\n');
			free(line);
			_exit(2);
		}
		else if (exit_arg == 1000)
			_exit(232);
		else
			_exit(exit_arg);
	}
}
