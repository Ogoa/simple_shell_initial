#include "main.h"
#define BUFFER_SIZE 200

/**
 * _getline - Reads an entire line from stream and stores the content
 * in a buffer
 * @lineptr: Double pointer referencing the buffer that will hold the content
 * of the line that has been read
 * @n: Pointer to the number of bytes of the memory block 'lineptr'
 * currently points to at the time of function call, if any
 * @fd: The file descriptor of the source
 *
 * Return: The number of charcters read from a line
 * Otherwise -1 on failure or when EOF is encountered
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	char *buffer;
	char c; /* Holds each character read from the stream */
	size_t i = 0;

	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		buffer = malloc(*n);
		if (buffer == NULL)
			return (-1);
	}
	while ((c = (char)_fgetc(fd)) != EOF)
	{
		if (i >= *n - 1) /* Check if buffer is full to prevent an overflow */
		{
			buffer = _realloc(buffer, *n, *n * 2);
			*n = *n * 2;
			if (buffer == NULL)
				return (-1);
		}
		*(buffer + i) = c;
		if (c == '\n') /* Terminate if the end of a line is reached */
		{
			*(buffer + ++i) = '\0';
			*lineptr = buffer;
			return (i);
		}
		i++;
	}
	free(buffer);
	return (-1);
}
