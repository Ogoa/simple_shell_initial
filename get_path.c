#include "main.h"

/**
 * get_full_path - Creates the absolute path for a file based
 * on the given file name and PATH directory
 * @full_path: Buffer to store address of the string with the full directory
 * path
 * @n: The size of the buffer in bytes
 * @file: Name of the file
 * @path_dir: The PATH directory
 *
 * Return: 0 on success, 1 on failure
 */
int get_full_path(char **full_path, size_t *n, const char *file,
		const char *path_dir)
{
	size_t i = 0;
	size_t j = 0;

	if (*full_path == NULL || *n == 0)
	{
		*n = 120;
		*full_path = malloc(*n);
		if (*full_path == NULL)
			return (1);
	}
	while (*(path_dir + i) != '\0')
	{
		if (i >= *n - 1)
		{
			*full_path = _realloc(*full_path, *n, *n * 2);
			*n = *n * 2;
			if (*full_path == NULL)
				return (1);
		}
		*(*full_path + i) = *(path_dir + i);
		i++;
	}
	if (i > 0 && *(*full_path + (i - 1)) != '/')
		*(*full_path + i) = '/';
	i++;
	while (*(file + j) != '\0')
	{
		if (i >= *n - 1)
		{
			*full_path = _realloc(*full_path, *n, *n * 2);
			*n = *n * 2;
			if (*full_path == NULL)
				return (1);
		}
		*(*full_path + i) = *(file + j);
		j++;
		i++;
	}
	*(*full_path + i) = '\0';
	return (0);
}
