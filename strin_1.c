#include "main.h"

/**
 * strcat - a function that concatenate two strings
 * @dest: char pointer the dest of the copied str
 * @src: const char pointer the source of str
 * Return: the dest
 */
char *strcat(char *dest, const char *src)
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
 * strcpy - function that  copies the
 * string pointed to by src
 * @dest: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 * Return: the char
 */
char strcpy(char *dest, char *src)
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
 * strcmp - Function that compares two strings
 * @s1: first typestring to be compared
 * @s2: second type string to be compared
 * Return: successs
 */

int strcmp(char *s1, char *s2)
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
 * strchr - function that locates a character in a strin
 * @str: the string
 * @c: character
 * Return: the pointer to the first occurrence of the character c
 */
char *strchr(char *str, char c)
{
	unsigned int index = 0;

	for (; *(s + index) != '\0'; index++)
		if (*(s + index) == c)
			return (s + index);
	if (*(s + index) == c)
		return (s + index);
	return ('\0');
}
/**
 * strspn - gets the length of a prefix substring
 * @str: initial segment
 * @accept: accepted bytes
 * Return: the number of accepted bytes
 */
int strspn(char *str, char *accept)
{
	int index, j, bool;

	for (index = 0; *(s + index) != '\0'; index++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + index) == *(accept + j))
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
