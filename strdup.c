#include "main.h"

/**
 * _strdup - Create a memory block to hold a duplicate of an
 * existing string
 * @str: Pointer to the string being duplicated
 *
 * Return: Address of the memory block holding the duplicated string
 * Otherwise, NULL if the function fails
 */
char *_strdup(const char *str)
{
	char *dup_str;
	int str_length = 0;
	int i = 0;

	if (str == NULL)
		return (NULL);
	while (*(str + str_length) != '\0')
		str_length++;
	dup_str = malloc((sizeof(char) * str_length) + 1);
	if (dup_str == NULL)
		return (NULL);
	while (*(str + i) != '\0')
	{
		*(dup_str + i) = *(str + i);
		i++;
	}
	*(dup_str + i) = '\0';
	return (dup_str);
}
