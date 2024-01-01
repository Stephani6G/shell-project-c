#include "main.h"

/**
 * get_length -   function that gets the length of a number
 * @n: type int number
 * Return: Lenght of a number
 */
int get_length(int n)
{
	unsigned int s;
	int len = 1;

	if (n < 0)
	{
		len++;
		s = n * -1;
	}
	else
	{
		s = n;
	}
	while (s > 9)
	{
		len++;
		s = s / 10;
	}

	return (len);
}
/**
 * aux_itoa - function converts int to string
 * @n: type int number
 * Return: String converted
 */
char *aux_itoa(int n)
{
	unsigned int s;
	int len = get_length(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + len) = '\0';

	if (n < 0)
	{
		s = n * -1;
		buffer[0] = '-';
	}
	else
	{
		s = n;
	}

	len--;
	do	{
		*(buffer + len) = (s % 10) + '0';
		s = s / 10;
		len--;
	} while (s > 0);
	return (buffer);
}
/**
 * _atoi - converts a string to an integer
 * @str: input string
 * Return: integer
 */
int _atoi(char *str)
{
	unsigned int count = 0, size = 0, o = 0, p = 1, m = 1, i;

	while (*(str + count) != '\0')
	{
		if (size > 0 && (*(str + count) < '0' || *(str + count) > '9'))
			break;

		if (*(str + count) == '-')
			p *= -1;

		if ((*(str + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		o = o + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (o * p);
}
