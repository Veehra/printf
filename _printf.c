#include "main.h"

/**
 * _printf - a function that produces output according to a format and argument
 * @format: string containing the regular chars and format specifiers to print
 *
 * Return: the total number of characters printed
 */
int _printf(const char *format, ...)
{
	/* Declare a variable list, with its own argument(begins at va_start) */
	va_list list;
	int i = 0, count = 0;
	/* a function pointer, that accepts va_list as argument */
	int (*ptr_func)(va_list);

	/* Returns -1 if format is null */
	if (!format || (format[i] == '%' && format[i + 1] == '\0'))
		return (-1);
	if (!format[i])
		return (0);

	va_start(list, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			ptr_func = get_func(format, i + 1);
			if (ptr_func == NULL)
			{
				_putchar('%');
				count++;
			}
			else
			{
				count += ptr_func(list);
				i += get_nflags(format, i + 1);
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	return (count);
}
