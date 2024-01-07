#include "main.h"

/**
 * get_error - functionthat calls the error
 * according to the builtin, sytax or permission
 * @dtsh: data structure
 * @eval: error value
 * Return: error
 */
int get_error(datashel *datash, int eval)
{
	char *error;

	switch (eval)
	{
		case -1:
			error = error_env(dtsh);
			break;
		case 126:
			error = error_path_126(dtsh);
			break;
		case 127:
			error = error_not_found(dtsh);
			break;
		case 2:
			if (_str_cmp("exit", dtsh->args[0]) == 0)
				error = error_exit_shell(dtsh);
			else if (_str_cmp("cd", dtsh->args[0]) == 0)
				error = error_get_cd(dtsh);
			break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _str_len(error));
		free(error);
	}

	dtsh->status = eval;
	return (eval);
}
