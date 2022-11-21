#include "main.h"

/**
 * get_func - gets a particular function
 * @str: the string
 * @id: the index / function
 *
 * This function is called from the _printf function after % is encountered
 * It will return NULL if the char after % is not a specifier and just print %
 *
 * Return: a pointer to the function
 */
int (*get_func(const char *str, int id))(va_list)
{
	/* fns is an array of structs containing the format and its function */
	prn fns[] = {
		{"c", print_char}, {"s", print_str},
		{"%", print_percent}, {"i", print_number},
		{"d", print_number}, {NULL, NULL}
	};
	int i = 0, j = 0;

	if (str)
	{
		while (fns[i].func != NULL)
		{
			if (fns[i].c[j] == str[id])
			{
				if (fns[i].c[j + 1] == '\0')
				{
					return (fns[i].func);
				}
				else
				{
					i--;
					j++;
					id++;
				}
			}
			i++;
		}
	}

	return (NULL);
}
