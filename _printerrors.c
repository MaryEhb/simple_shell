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
/**
* _errtoi - converts a string to integer
* @s: string
*
* Return: 0 if no found numbers in string, converted number otherwise
*/
int _errtoi(char *s)
{
	int i = 0;
	unsigned long int res = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			res *= 10;
			res += (s[i] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}
