#include "main.h"

/**
 * check_path - check if the command has an absolute path
 * @command: command string to be checked
 * Return: 0 if Absolute path or 1 if Relative path
 */

int check_path(char *command)
{
	if (command[0] == '/' || (command[0] == '.' && command[1] == '/') || (command[0] == '.' && command[1] == '.' && command[2] == '/'))
		return (0);
	return (1);
}
