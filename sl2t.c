#include "main.h"

/**
 * addnode - function that adds separators
 * and command lines in the lists
 * @head_s: head of separator list
 * @head_l: head of command lines list
 * @inputs: input string
 */
void addnode(sep_l **head_s, line_l **head_l, char *inputs)
{
	int i;
	char *line;

	inputs = swapd_chars(inputs, 0);

	for (i = 0; inputs[i]; i++)
	{
		if (inputs[i] == ';')
			add_sep_node_end(head_s, inputs[i]);

		if (inputs[i] == '|' || inputs[i] == '&')
		{
			add_sep_node_end(head_s, inputs[i]);
			i++;
		}
	}

	line = _str_tok(inputs, ";|&");
	do {
		line = swapd_chars(line, 1);
		add_line_node_end(head_l, line);
		line = _strtok(NULL, ";|&");
	} while (line != NULL);

}
