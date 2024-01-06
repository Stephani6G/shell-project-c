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
				add_var_nodes(h, j, _envr[row] + chr + 1, lval);
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

	add_var_nodes(h, j, NULL, 0);
}
/**
 * check_vars - function to check if the typed variable is $$ or $?
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: void success always
 */
int check_vars(r_vars **h, char *in, char *st, datashel *data)
{
	int i, lst, lpd;

	lst = _str_len(st);
	lpd = _str_len(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				add_var_nodes(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				add_var_nodes(h, 2, data->pid, lpd), i++;
			else if (in[i + 1] == '\n')
				add_var_nodes(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				add_var_nodes(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				add_var_nodes(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				add_var_nodes(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				add_var_nodes(h, 0, NULL, 0);
			else
				check_env(h, in + i, data);
		}
	}

	return (i);
}
