#include "main.h"

/**
 * _strchr - Search for the occurrence of a specified character
 * in a given string
 * @str: Pointer to the string being evaluated for the occurrence of
 * the character
 * @c: The character being searched for in 'str'
 *
 * Return: Pointer to the position of the character in the string
 * if a match is found
 * Otherwise, NULL if no match is found
 */
char *_strchr(const char *str, char c)
{
	int i = 0;

	if (str == NULL || c == 0)
		return (NULL);
	while (*(str + i) != '\0')
	{
		if (c == *(str + i))
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
