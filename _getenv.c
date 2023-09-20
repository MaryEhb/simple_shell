#include "main.h"

/**
 * _getenv - Get env variable by key
 * @env: env from main args
 * @env_variable: key of needed value
 * Return: value of key if found. Otherwise return NULL
 */

char *_getenv(char **env, char *env_variable)
{
	char *cpy;
	char *key;
	char *value, *cvalue;
	int i = 0;

	while (env[i])
	{
		cpy = (char *) malloc(_strlen(env[i]) + 1);
		if (!cpy)
			return (NULL);

		_strcpy(cpy, env[i]);
		key = strtok(cpy, "=");
		value = strtok(NULL, "=");


		if (_strcmp(key, env_variable) == 0)
		{
			cvalue = (char *) malloc(_strlen(value) + 1);
			_strcpy(cvalue, value);

			free(cpy);
			return (cvalue);
		}

		i++;

		free(cpy);
	}

	return (NULL);
}
