#include "main.h"

/**
 * get_nflags - gets a particular function
 * @str: the string
 * @id: the index / function
 *
 * This function is called from the _printf function after % is encountered
 * It will return NULL if the char after % is not a specifier and just print %
 *
 * Return: number of characters to skip
 */
int get_nflags(const char *str, int id)
{
	prn fns[] = {
		{"c", print_char}, {"d", print_number},
		{"s", print_str}, {"%", print_percent}, {NULL, NULL}
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
					return (j + 1);
				}
				else
				{
					i--;
					j++;
					id++;
				}
			} i++;
		}
	}
	return (0);
}
