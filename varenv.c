#include "main.h"

/**
 * check_env - checks if the typed variable is an env variable
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 */
void check_env(r_vars **h, char *in, datashel *data)
{
	int row, chr, j, lval;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = _str_len(_envr[row] + chr + 1);
				add_rvar_nodes(h, j, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[j] == _envr[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	add_rvar_nodes(h, j, NULL, 0);
}
