#include "main.h"

/**
 * _str_dup - a function that  duplicates a
 * string in the heap memory
 * @str: Type char pointer string
 * Return: duplicated string
 */
char *_str_dup(const char *str)
{
	char *newstr;
	size_t len;

	len = _str_len(str);
	newstr = malloc(sizeof(char) * (len + 1));
	if (newstr == NULL)
		return (NULL);
	_memcpy(newstr, str, len + 1);
	return (newstr);
}

/**
 * _str_len - Returns the length of a string
 * @str: Type char pointer
 * Return: Always 0.
 */
int _str_len(const char *str)
{
	int len;

	for (len = 0; str[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmpr_char -  a function compare chars of strings
 * @str: input string
 * @dlm: delimiter
 * Return: 1 if are equals, 0 if not.
 */
int cmpr_char(char str[], const char *dlm)
{
	unsigned int index, j, k;

	for (index = 0, k = 0; str[index]; index++)
	{
		for (j = 0; dlm[j]; j++)
		{
			if (str[index] == dlm[j])
			{
				k++;
				break;
			}
		}
	}
	if (index == k)
		return (1);
	return (0);
}
