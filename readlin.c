#include "main.h"

/**
 * readlin - reads the input string
 * @i_eof: return value of getline function
 * Return: input string
 */
char *readlin(int *i_eof)
{
	char *inputs = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&inputs, &bufsize, stdin);

	return (inputs);
}
