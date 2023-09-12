#include "main.h"

/**
 * _puts - prints a string
 * @str: pointer to string
 * Return: nothing
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
