#include "main.h"

/**
 * repeat_chars - function that counts the repetitions of a char
 * @inputs: input string
 * @index: index
 * Return: repetitions
 */
int repeat_chars(char *inputs, int index)
{
	if (*(inputs - 1) == *inputs)
		return (repeat_chars(inputs - 1, index + 1));

	return (index);
}
/**
 * err_sep - function that finds syntax errors
 * @inputs: input string
 * @index: index
 * @last: last char read
 * Return: index of error. 0 when there are no
 */
int err_sep(char *inputs, int index, char last)
{
	int count;

	count = 0;
	if (*inputs == '\0')
		return (0);

	if (*inputs == ' ' || *inputs == '\t')
		return (err_sep(inputs + 1, index + 1, last));

	if (*inputs == ';')
		if (last == '|' || last == '&' || last == ';')
			return (index);

	if (*inputs == '|')
	{
		if (last == ';' || last == '&')
			return (index);

		if (last == '|')
		{
			count = repeat_chars(inputs, 0);
			if (count == 0 || count > 1)
				return (index);
		}
	}

	if (*inputs == '&')
	{
		if (last == ';' || last == '|')
			return (index);

		if (last == '&')
		{
			count = repeat_chars(input, 0);
			if (count == 0 || count > 1)
				return (index);
		}
	}

	return (err_sep(inputs + 1, index + 1, *inputs));
}
/**
 * find_first_char - function that  finds the
 * index of the first char
 * @inputs: input string
 * @index: index
 * Return: 1 if there is an error. 0 in other case.
 */
int find_first_char(char *inputs, int *index)
{

	for (*index = 0; inputs[*index]; *index += 1)
	{
		if (inputs[*index] == ' ' || inputs[*index] == '\t')
			continue;

		if (inputs[*index] == ';'
				|| inputs[*index] == '|' || inputs[*index] == '&')
			return (-1);

		break;
	}

	return (0);
}
/**
 * print_syntx_err - funxtion that prints when a syntax error is found
 * @dtsh: data structure
 * @inputs: input string
 * @index: index of the error
 * @bool: to control msg error
 * Return: no return success always
 */
void print_syntx_err(datashel *dtsh, char *inputs, int index, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (inputs[index] == ';')
	{
		if (bool == 0)
			msg = (inputs[index + 1] == ';' ? ";;" : ";");
		else
			msg = (inputs[index - 1] == ';' ? ";;" : ";");
	}

	if (inputs[index] == '|')
		msg = (inputs[index + 1] == '|' ? "||" : "|");

	if (inputs[index] == '&')
		msg = (inputs[index + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = aux_itoa(dtsh->counter);
	length = strlen(dtsh->agv[0]) + strlen(counter);
	length += strlen(msg) + strlen(msg2) + strlen(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	strcpy(error, dtsh->agv[0]);
	strcat(error, ": ");
	strcat(error, counter);
	strcat(error, msg2);
	strcat(error, msg);
	strcat(error, msg3);
	strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}
/**
 * check_syntx_err - intermediate function to
 * find and print a syntax error
 * @dtsh: data structure
 * @inputs: input string
 * Return: 1 if there is an error. 0 in other case
 */
int check_syntx_err(datashel *dtsh, char *inputs)
{
	int begin = 0;
	int f_char = 0;
	int i = 0;

	f_char = first_char(inputs, &begin);
	if (f_char == -1)
	{
		print_syntx_err(dtsh, inputs, begin, 0);
		return (1);
	}

	i = err_sep(inputs + begin, 0, *(inputs + begin));
	if (i != 0)
	{
		print_syntx_err(dtsh, inputs, begin + i, 1);
		return (1);
	}

	return (0);
}
