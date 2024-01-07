#include "main.h"

/**
 * get_help - function that retrieves help messages according to builtin
 * @dtsh: data structure
 * Return: 0
 */
int get_help(datashel *dtsh)
{
	char *data = dtsh->args[1];

	if (data == 0)
		help_general();
	else if (_str_cmp(data, "setenv") == 0)
		help_setenv();
	else if (_str_cmp(data, "env") == 0)
		help_environ();
	else if (_str_cmp(data, "unsetenv") == 0)
		help_unsetenv();
	else if (_str_cmp(data, "help") == 0)
		help_b();
	else if (_str_cmp(data, "exit") == 0)
		help_exit();
	else if (_str_cmp(data, "cd") == 0)
		help_cd();
	else if (_str_cmp(data, "alias") == 0)
		help_alias();
	else
		write(STDERR_FILENO, dtsh->args[0], _str_len(dtsh->args[0]));

	dtsh->status = 0;
	return (1);
}
