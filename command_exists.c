#include "main.h"

/**
 * command_exists - check if a command with a given path exists
 * @command: command with absolute path
 * Return: 1 if exist. 0 if it doesn't exist
 */

int command_exists(char *command)
{
	if (access(command, F_OK) == 0)
		return (1);
	return (0);
}
