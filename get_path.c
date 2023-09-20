#include "main.h"

/**
 * get_path - find the full path of a command using
 * the PATH environment variable
 * @envp: env from main args
 * @command: command to be run
 * Return: full path
 */

char *get_path(char **envp, char *command)
{
	char *new_command = NULL, *token;
	char *path = _getenv(envp, "PATH");
	DIR *dir;
	struct dirent *entity;

	if (!path)
		return (NULL);
	token = strtok(path, ":");
	while (token)
	{
		dir = opendir(token);
		if (!dir)
			continue;
		entity = readdir(dir);
		while (entity)
		{
			if ((strcmp(entity->d_name, command)) == 0)
			{
				new_command = (char *) malloc(_strlen(token) + _strlen(command) + 2);
				if (new_command == NULL)
				{
					free(path);
					return (NULL);
				}
				_strcpy(new_command, token);
				_strcat(new_command, "/");
				_strcat(new_command, command);

				closedir(dir);
				free(path);
				return (new_command);
			}
			entity = readdir(dir);
		}
		token = strtok(NULL, ":");
		closedir(dir);
	}
	free(path);
	free(new_command);
	return (command);
}
