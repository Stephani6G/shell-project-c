#include "main.h"

/**
 * swapd_chars -  function that swaps | and & for non-printed chars
 * @inputs: input string
 * @bool: type of swap
 * Return: swapped string
 */
char *swapd_chars(char *inputs, int bool)
{
	int i;

	if (bool == 0)
	{
		for (i = 0; inputs[i]; i++)
		{
			if (inputs[i] == '|')
			{
				if (inputs[i + 1] != '|')
					inputs[i] = 16;
				else
					i++;
			}

			if (inputs[i] == '&')
			{
				if (inputs[i + 1] != '&')
					inputs[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; inputs[i]; i++)
		{
			inputs[i] = (inputs[i] == 16 ? '|' : inputs[i]);
			inputs[i] = (inputs[i] == 12 ? '&' : inputs[i]);
		}
	}
	return (inputs);
}
