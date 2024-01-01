#include "main.h"

/**
 * _str_cat - a function that concatenate two strings
 * @dest: char pointer the dest of the copied str
 * @src: const char pointer the source of str
 * Return: the dest
 */
char _str_cat(char *dest, const char *src)
{
	int index;
	int j;

	for (index = 0; dest[index] != '\0'; index++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[index] = src[j];
		index++;
	}

	dest[index] = '\0';
	return (dest);
}
/**
 * _str_cpy - function that  copies the
 * string pointed to by src
 * @dest: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 * Return: the char
 */
char _str_cpy(char *dest, char *src)
{

	size_t ap;

	for (ap = 0; src[ap] != '\0'; ap++)
	{
		dest[ap] = src[ap];
	}
	dest[ap] = '\0';

	return (dest);
}
/**
 * _str_cmp - Function that compares two strings
 * @s1: first typestring to be compared
 * @s2: second type string to be compared
 * Return: successs
 */

int _str_cmp(char *s1, char *s2)
{
	int index;

	for (index = 0; s1[index] == s2[index] && s1[index]; index++)
		;

	if (s1[index] > s2[index])
		return (1);
	if (s1[index] < s2[index])
		return (-1);
	return (0);
}
/**
 * _str_chr - function that locates a character in a string
 * @str: the string
 * @c: character
 * Return: the pointer to the first occurrence of the character c
 */
char _str_chr(char *str, char c)
{
	unsigned int index = 0;

	for (; *(str + index) != '\0'; index++)
		if (*(str + index) == c)
			return (str + index);
	if (*(str + index) == c)
		return (str + index);
	return ('\0');
}
/**
 * _str_spn - gets the length of a prefix substring
 * @str: initial segment
 * @accept: accepted bytes
 * Return: the number of accepted bytes
 */
int _str_spn(char *str, char *accept)
{
	int index, j, bool;

	for (index = 0; *(str + index) != '\0'; index++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(str + index) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (index);
}
