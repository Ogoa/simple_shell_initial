#include "main.h"

/**
 * _putchar - Prints an individual character
 * @c: The character literal to be printed
 *
 * Return: 1 on success
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
