#include "main.h"

/**
 * _memcpy - Copies the contents of one memry block to another memory block
 * @dest: Pointer to the memory block where the bytes are being copied to
 * @src: Pointer to the memory block whose bytes are being copied to 'dest'
 * @nmemb: The number of bytes to copy from 'src' to 'dest'
 *
 * Return: Nothing
 * Description: In this implementation, 'dest' and 'src' are always assumed
 * to be of equal size. Alternative use may result to undefined behaviour
 */
void _memcpy(char *dest, const char *src, size_t nmemb)
{
	size_t i = 0;

	if (src == NULL || dest == NULL)
		return;
	for (i = 0; i < nmemb; i++)
		*(dest + i) = *(src + i);
}
