#include "main.h"

/**
 * _realloc - Resizes a given block of memory and copies the existing
 * memory area to the newly created block
 * @ptr: Pointer to the memory block that is to be resized
 * @old_size: The number of bytes currently occupied by 'ptr'
 * @new_size: The number of bytes to be allocated to the new memory block
 *
 * Return: Pointer to the newly created memory block, otherwise return NULL
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (ptr == NULL || old_size == 0) /* Equivalent to malloc */
	{
		ptr = malloc(new_size);
		if (ptr == NULL) /* If malloc fails */
			return (NULL);
		return (ptr);
	}
	if (new_size == 0 && ptr) /**
				    * ptr has to be non-null for
				    * it to be freed
				    */
	{
		free(ptr);
		return (ptr);
	}
	if (old_size == new_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (old_size < new_size)
	{
		_memcpy((char *)new_ptr, (char *)ptr, old_size);
		free(ptr);
	}
	else
	{
		_memcpy((char *)new_ptr, (char *)ptr, new_size);
		free(ptr);
	}
	return (new_ptr);
}
