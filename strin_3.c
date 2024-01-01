#include "main.h"

/**
 * _str_tok - a function that splits a
 * string by some delimiter
 * @str: input string
 * @dlm: delimite
 * Return: string splited
 */
char *_str_tok(char str[], const char *dlm)
{
	static char *splitd, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmpr_char(str, dlm))
			return (NULL);
		splitd = str;
		i = _str_len(str);
		str_end = &str[i];
	}
	str_start = splitd;
	if (str_start == str_end)
		return (NULL);

	for (bool = 0; *splitd; splitd++)
	{
		if (splitd != str_start)
			if (*splitd && *(splitd - 1) == '\0')
				break;
		for (i = 0; dlm[i]; i++)
		{
			if (*splitd == dlm[i])
			{
				*splitd = '\0';
				if (splitd == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitd)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (str_start);
}
/**
 * _is_digit - function that defines if string passed is a number
 * @str: input string
 * Return: 1 if string is a number. 0 in other case
 */
int _is_digit(const char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}
