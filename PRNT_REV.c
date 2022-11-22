#include "main.h"

/**
 * print_rev - prints a string using a loop that also counts the characters
 * @args: arguments
 *
 * Return: count
 */
int print_rev(va_list args)
{
	int i, j;
	char *str;
	char null[] = "(null)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; null[i] != '\0'; i++)
			_putchar(null[i]);
		return (6);
	}

	for (i = 0; str[i] != '\0'; i++)
		;
	for (j = i - 1; j >= 0; j--)
		_putchar(str[j]);

	return (i);
}
