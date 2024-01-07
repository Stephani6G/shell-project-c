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
		aux_help_general();
	else if (_str_cmp(data, "setenv") == 0)
		aux_help_setenv();
	else if (_str_cmp(data, "env") == 0)
		aux_help_env();
	else if (_str_cmp(data, "unsetenv") == 0)
		aux_help_unsetenv();
	else if (_str_cmp(data, "help") == 0)
		aux_help();
	else if (_str_cmp(data, "exit") == 0)
		aux_help_exit();
	else if (_str_cmp(data, "cd") == 0)
		aux_help_cd();
	else if (_str_cmp(data, "alias") == 0)
		aux_help_alias();
	else
		write(STDERR_FILENO, dtsh->args[0], _str_len(dtsh->args[0]));

	dtsh->status = 0;
	return (1);
}
