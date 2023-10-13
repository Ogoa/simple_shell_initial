#include "main.h"

/**
 * _strcmp - Compares two strings to evaluate if they are similar
 * @str1: The first string
 * @str2: The second string
 *
 * Return: 0 if the two strings are similar, otherwise 1
 */
int _strcmp(const char *str1, const char *str2)
{
	size_t i = 0;
	size_t str1_len = 0;
	size_t str2_len = 0;

	if (str1 == NULL || str2 == NULL)
		return (-1);
	str1_len = _strlen(str1);
	str2_len = _strlen(str2);
	if (str1_len != str2_len)
		return (1);
	for (i = 0; i < str2_len; i++)
	{
		if (*(str1 + i) != *(str2 + i))
			return (1);
	}
	return (0);
}

/**
 * _strlen - Evaluates the length of a given string
 * @str: Pointer to the string that is to be evaluated
 *
 * Return: The number of bytes occupied by the string
 * Otherwise, 0 on failure
 */
size_t _strlen(const char *str)
{
	size_t str_length = 0;

	if (str == NULL)
		return (0);
	while (*(str + str_length) != '\0')
		str_length++;
	return (str_length);
}
