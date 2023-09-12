#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: first character in string pointer
 * Return: string length
 */

int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		s++;
		count++;
	}

	return (count);
}
