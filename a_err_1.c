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

	strcpy(errorm, dtsh->agv[0]);
	strcat(errorm, ": ");
	strcat(errorm, vr_str);
	strcat(errorm, ": ");
	strcat(errorm, dtsh->args[0]);
	strcat(errorm, text);
	strcat(errorm, "\0");
	free(vr_str);

	return (errorm);
}
/**
 * path_error - error message displayed for path failure
 * and failure denied permission
 * @dtsh: data relevant
 * Return: The error string
 */
char *path_error(datashel *dtsh)
{
	int len;
	char *vr_str;
	char *errorm;

	vr_str = aux_itoa(dtsh->count);
	len = strlen(dtsh->agv[0]) + strlen(vr_str);
	len += strlen(dtsh->args[0]) + 24;
	errorm = malloc(sizeof(char) * (len + 1));
	if (errorm == 0)
	{
		free(errorm);
		free(vr_str);
		return (NULL);
	}
	strcpy(errorm, dtsh->agv[0]);
	strcat(errorm, ": ");
	strcat(errorm, vr_str);
	strcat(errorm, ": ");
	strcat(errorm, dtsh->args[0]);
	strcat(errorm, ": Permission denied\n");
	strcat(errorm, "\0");
	free(vr_str);
	return (errorm);
}
