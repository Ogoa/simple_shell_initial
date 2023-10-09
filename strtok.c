#include "main.h"

/**
 * _strtok - Extracts tokens from a string
 * @str: Pointer to the string being evaluated for the occurrence
 * of tokens if any
 * @delim: Pointer to a string specifying the individual bytes that
 * are delimiters in 'str'
 *
 * Return: Pointer to the token
 * Description: In the first invocation of this function, 'str' must be
 * specified. iOn subsequent calls, 'str' must be NULL
 * This function maintains an internal state of the value of 'str' from
 * the first call
 */
char *_strtok(char *str, const char *delim)
{
	static char *string; /* String to be parsed */
	char *token; /* Pointer to a copy of the token */
	int i = 0;
	int n = 0;

	if (str != NULL)
		string = str;
	if (*string != '\0')
	{
		/* Parsig the string until a delimiter is encountered */
		while (*(string + i) != '\0' && _strchr(delim, *(string + i)) == NULL)
		{
			i++;
		}
		if (i == 0) /* Handling consecutive delimiters */
		{
			string++;
			return (_strtok(NULL, delim));
		}
		token = malloc((sizeof(char) * i) + 1);
		if (token == NULL)
			return (NULL);
		for (n = 0; n < i; n++)
		{
			*(token + n) = *string;
			string++;
		}
		*(token + n) = '\0';
		if (*string != '\0')
			string++;
		return (token);
	}
	return (NULL);
}
