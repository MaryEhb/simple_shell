#include "main.h"

/**
 * _strcmp - compares two strings.
 * @s1: str1
 * @s2: str2
 * Return: 0 if same, 1 if diff
 */

int _strcmp(char *s1, char *s2)
{
	int notequal = 0;
	int i = 0;

	while (s1[i] != '\0' && !notequal)
	{
		if (s1[i] != s2[i])
		{
			notequal = (int)s1[i] - (int)s2[i];
			break;
		}

		i++;
		if (s1[i] == '\0' && s1[i] == s2[i])
		{
			break;
		}
	}

	return (notequal);
}
