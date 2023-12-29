#include "main.h"

/**
 * err_env - the displayed error
 * message for environ
 * @dtsh: data relevant
 * Return: error message
 */
char *err_env(datashel *dtsh)
{
	int len;
	char *errorm;
	char *vr_str;
	char *text;

	vr_str = aux_itoa(dtsh->count);
	text = ": Unable to add/remove from environment\n";
	len = strlen(dtsh->agv[0]) + strlen(vr_str);
	len += strlen(dtsh->args[0]) + strlen(text) + 4;
	errorm = malloc(sizeof(char) * (len + 1));
	if (errorm == 0)
	{
		free(errorm);
		free(vr_str);
		return (NULL);
	}

	_strcpy(error, dtsh->agv[0]);
	_strcat(error, ": ");
	_strcat(error, vr_str);
	_strcat(error, ": ");
	_strcat(error, dtsh->args[0]);
	_strcat(errorm, text);
	_strcat(errorm, "\0");
	free(vr_str);

	return (error);
}
/**
 * error_path_126 - error message for path and failure denied permission.
 * @datash: data relevant (counter, arguments).
 *
 * Return: The error string.
 */
char *error_path_126(data_shell *datash)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}
