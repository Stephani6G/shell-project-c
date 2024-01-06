#include "main.h"

/**
 * replace_input - functionthat replaces string into variables
 * @head: head of the linked list
 * @inputs: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *replace_input(r_vars **head, char *inputs, char *new_input, int nlen)
{
	r_vars *indx;
	int i, j, k;

	indx = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (inputs[j] == '$')
		{
			if (!(indx->length_var) && !(indx->length_var))
			{
				new_input[i] = inputs[j];
				j++;
			}
			else if (indx->length_var && !(indx->length_var))
			{
				for (k = 0; k < indx->length_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx->length_var; k++)
				{
					new_input[i] = indx->value[k];
					i++;
				}
				j += (indx->length_var);
				i--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[i] = inputs[j];
			j++;
		}
	}

	return (new_input);
}
