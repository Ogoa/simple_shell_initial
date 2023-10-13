#include "main.h"

/**
 * builtins - Handles the implementation of shell built-in functions
 * @argv: Pointer to the array of argument strings
 *
 * Return: 1 on success, 0 on failure
 */
int builtins(char **argv)
{
	char **env = NULL;

	if (argv == NULL || *argv == NULL)
		return (0);
	if (_strcmp(argv[0], "exit") == 0)
	{
		_exit(0);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		for (env = environ; env && *env; env++)
		{
			print(*env);
			print("\n");
		}
		return (1);
	}
	return (0);
}
