#include "main.h"

/**
 * _fgetc - Read a character from a file
 * @fd: The file descriptor
 *
 * Return: The number of bytes read
 * EOF if no character has been read
 */
int _fgetc(int fd)
{
	char c;
	ssize_t bytes_read = 0;

	bytes_read = read(fd, &c, 1);
	if (bytes_read == -1 || bytes_read == 0)
		return (EOF);
	return ((int)c);
}
