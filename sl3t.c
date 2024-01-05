#include "main.h"

/**
 * go_to_next - go to the next command line stored
 * @list_s: separator list
 * @list_l: command line list
 * @dtsh: data structure
 */
void go_to_next(sep_l **list_s, line_l **list_l, datashel *dtsh)
{
	int loop_sep;
	sep_l *ls_s;
	line_l *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (dtsh->status == 0)
		{
			if (ls_s->sep == '&' || ls_s->sep == ';')
				loop_sep = 0;
			if (ls_s->sep == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->sep == '|' || ls_s->sep == ';')
				loop_sep = 0;
			if (ls_s->sep == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}
