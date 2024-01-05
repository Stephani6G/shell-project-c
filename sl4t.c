#include "main.h"

/**
 * split_coms - function that splits command lines according to
 * the separators ;, | and &, and executes them
 * @dtsh: data structure
 * @inputs: input string
 * Return: 0 to exit, 1 to continue
 */
int split_coms(datashel *dtsh, char *inputs)
{

	sep_l *head_s, *list_s;
	line_l *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	addnode(&head_s, &head_l, inputs);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		dtsh->input = list_l->lineui;
		dtsh->args = split_line(dtsh->input);
		loop = execle(datashel);
		free(dtsh->args);

		if (loop == 0)
			break;

		go_to_next(&list_s, &list_l, dtsh);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_sep_l(&head_s);
	free_line_l(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}
