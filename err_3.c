#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * error_shell_exit_shell -  error message for exit in shell
 * @dtsh: data relevant
 * Return: Error message
 */
char *error_shell_exit_shell(datashel *dtsh)
{
	int len;
	char *errorm;
	char *vr_str;

	vr_str = aux_itoa(dtsh->count);
	len = strlen(dtsh->agv[0]) + strlen(vr_str);
	len += strlen(dtsh->args[0]) + strlen(dtsh->args[1]) + 23;
	errorm = malloc(sizeof(char) * (len + 1));

	if (errorm == 0)
	{
		free(vr_str);
		return (NULL);
	}
	strcpy(errorm, dtsh->agv[0]);
	strcat(errorm, ": ");
	strcat(errorm, vr_str);
	strcat(errorm, ": ");
	strcat(errorm, dtsh->args[0]);
	strcat(errorm, ": foreign number: ");
	strcat(errorm, dtsh->args[1]);
	strcat(errorm, "\n\0");
	free(vr_str);

	return (errorm);
}
