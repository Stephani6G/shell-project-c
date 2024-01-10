#include "main.h"

/**
 * _memcpy - copies information between void pointers.
 * @newpointer:destination pointer
 * @pointer: source pointer
 * @size: size of the new pointer
 */
void _memcpy(void *newpointer, const void *pointer, unsigned int size)
{
	char *char_pointer = (char *)pointer;
	char *char_newpointer = (char *)newpointer;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newpointer[i] = char_pointer[i];
}

/**
 * _realloc -  function that reallocates a memory block
 * @pointer: pointer to the memory previously allocated
 * @old_size: size, in bytes, of the allocated space of ptr
 * @new_size: new size, in bytes, of the new memory block
 * Return: ptr
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *pointer, unsigned int old_size, unsigned int new_size)
{
	void *newpointer;

	if (pointer == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(pointer);
		return (NULL);
	}

	if (new_size == old_size)
		return (pointer);

	newpointer = malloc(new_size);
	if (newpointer == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newpointer, pointer, new_size);

	else
		_memcpy(newpointer, pointer, old_size);

	free(pointer);
	return (newpointer);
}
/**
 * _realocdp - a function that reallocates a memory
 * block of a double pointer
 * @pointer: double pointer to the memory  allocated
 * @old_size: size, in bytes, of the allocated space of ptr
 * @new_size: new size, in bytes, of the new memory block
 * Return: pointer
 * if new_size == old_size, returns ptr without changes
 * if malloc fails, returns NULL
 */
char **_realocdp(char **pointer, unsigned int old_size, unsigned int new_size)
{
	char **newpointer;
	unsigned int i;

	if (pointer == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (pointer);

	newpointer = malloc(sizeof(char *) * new_size);
	if (newpointer == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newpointer[i] = pointer[i];

	free(pointer);

	return (newpointer);
}
