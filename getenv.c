#include "main.h"

/**
 * _getenv - Searches the environment list for a particular environment
 * variable
 * @name: Pointer to a string containing the name of the variable
 * being searched for
 *
 * Return: Pointer to the corresponding 'value' of the name,value pair
 * of an environment variable
 * Otherwise, NULL if no match is found
 */
char *_getenv(const char *name)
{
	/* extern char **environ; */
	char *env_variable;
	char *env_name;
	char *env_value;
	const char *delim = "=";
	char *value;
	size_t i = 0;
	size_t value_len = 0;

	if (*environ == NULL && environ == NULL)
		return (NULL);
	while ((env_variable = *(environ + i)) != NULL)
	{
		env_name = _strtok(env_variable, delim);
		env_value = _strtok(NULL, delim);
		if (env_name && env_value && _strcmp(env_name, name) == 0)
		{
			value_len = _strlen(env_value);
			value = malloc((sizeof(char) * value_len) + 1);
			if (value == NULL)
				return (NULL);
			value_len = 0;
			while (*(env_value + value_len) != '\0')
			{
				*(value + value_len) = *(env_value + value_len);
				value_len++;
			}
			*(value + value_len) = '\0';
			free(env_name);
			free(env_value);
			return (value);
		}
		i++;
	}
	return (NULL);
}
