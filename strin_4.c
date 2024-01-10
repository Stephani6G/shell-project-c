#include "main.h"

/**
 * rev_string - a function that  reverses a string
 * @str: input string
 * Return: no return
 */
void rev_string(char *str)
{
	int count = 0, i, j;
	char *sr, temp;

	while (count >= 0)
	{
		if (str[count] == '\0')
			break;
		count++;
	}
	sr = str;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(sr + j);
			*(sr + j) = *(sr + (j - 1));
			*(sr + (j - 1)) = temp;
		}
	}
}
