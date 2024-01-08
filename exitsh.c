#include "main.h"

/**
 * exit_shell - function that  exits the shell
 * @dtsh: relevant data
 * Return: 0 on success
 */
int exit_shell(datashel *dtsh)
{
	unsigned int ustatus;
	int _is_digit, str_len, big_number;

	if (datas->args[1] != NULL)
	{
		ustatus = _atoi(dtsh->args[1]);
		is_digit = _isdigit(dtsh->args[1]);
		_str_len = _strlen(dtsh->args[1]);

		big_number = ustatus > (unsigned int)INT_MAX;

		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(dtsh, 2);
			dtsh->status = 2;
			return (1);
		}

		dtsh->status = (ustatus % 256);
	}

	return (0);
}
