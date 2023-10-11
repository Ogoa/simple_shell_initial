#include "main.h"

/**
 * print - Prints a string
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 * Otherwise 0 on failure
 */
int print(const char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (*(str + i) != '\0')
	{
		_putchar(*(str + i));
		i++;
	}
	return (i);
}
