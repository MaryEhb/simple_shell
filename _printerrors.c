#include "main.h"

/**
*_errputs - prints an input string
* @s: print s to stderr
*
* Return: Nothing
*/
void _errputs(char *s)
{
	int i = 0;
	if (!s)
		return;
	while (s[i] != '\0')
	{
		_errputchar(s[i]);
		i++;
	}
}

/**
* _errputchar - writes the character c to stderr
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _errputchar(char c)
{
	return (write(2, &c, 1));
}

