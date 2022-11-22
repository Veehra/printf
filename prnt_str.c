#include "main.h"

/**
 * print_STR - also prints hex values of characters that are not printable
 * @args: arguments
 *
 * Return: count
 */
int print_STR(va_list args)
{
	int i, n = 0;
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
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar(92);
			_putchar('x');
			print_HEX((long int)str[i], 2, 1);
			n += 3;
		}
		else
		{
			_putchar(str[i]);
		}
	}
	return (i + n);
}
