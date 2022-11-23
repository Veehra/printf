#include "main.h"

/**
 * print_str - prints a string using a loop that also counts the characters
 * @args: arguments
 *
 * Return: count
 */
int print_str(va_list args)
{
	int i;
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
	{
		_putchar(str[i]);
	}
	return (i);
}
