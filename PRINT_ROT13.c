#include "main.h"

/**
 * print_rot13 - prints a string using a loop that also counts the characters
 * @args: arguments
 *
 * Return: count
 */
int print_rot13(va_list args)
{
	int i, r;
	char *str;
	char org[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *rot13;

	str = va_arg(args, char *);
	rot13 = malloc(sizeof(char) * (strlen(str) + 1));
	if (rot13 == NULL)
	{
		return (0);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
	if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
		{
			for (r = 0; org[r] != '\0'; r++)
			{
				if (str[i] == org[r])
				{
					rot13[i] = rot[r];
					break;
				}
			}
		}
		else
		{
			rot13[i] = str[i];
		}
	}
	rot13[i] = '\0';

	for (i = 0; rot13[i] != '\0'; i++)
	{
		_putchar(rot13[i]);
	}

	free(rot13);
	return (i);
}
