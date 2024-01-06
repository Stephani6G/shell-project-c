#include "main.h"

/**
 * remove_comment - fuction that  deletes comments from the input string
 * @in: input string
 * Return: input without comments
 */
char *remove_comment(char *in)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
	{
		in = _realloc(in, i, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}
/**
 * shell_looped - func that loops  a shell
 * @dtsh: data relevant
 */
void shell_looped(datashel *dtsh)
{
	int loop, i_eof;
	char *inputs;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		inputs = read_link(&i_eof);
		if (i_eof != -1)
		{
			inputs = remove_comment(inputs);
			if (inputs == NULL)
				continue;

			if (check_syntx_err(dtsh, inputs) == 1)
			{
				dtsh->status = 2;
				free(inputs);
				continue;
			}
			inputs = rep_var(inputs, dtsh);
			loop = split_coms(dtsh, inputs);
			dtsh->count += 1;
			free(inputs);
		}
		else
		{
			loop = 0;
			free(inputs);
		}
	}
}
