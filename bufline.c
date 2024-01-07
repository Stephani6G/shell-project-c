#include "main.h"

/**
 * buf_line - func that assigns the line var for get_line
 * @lineptr: Buffer that stores the input str
 * @n: size of line
 * @buffer: string called to line
 * @j: size of buffer
 */
void buf_line(char **lineptr, size_t *n, char *buffer, size_t j)
{
	if ((*lineptr == NULL) || (*n < j))
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_str_spn(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * gets_line - read input from stream
 * @lineptr: buffer that stores input
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: Number of bytes
 */
ssize_t gets_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buffer, t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);

	input = 0;
	buffer = malloc(sizeof(char) * BUFSIZE);

	if (buffer == 0)
		return (-1);

	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input++] = t;
	}
	buffer[input] = '\0';
	buf_line(lineptr, n, buffer, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}
