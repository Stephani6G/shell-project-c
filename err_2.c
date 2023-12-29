#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * error_fetch_cd - error message for cd command in get_cd
 * @dtsh: data relevant
 * Return: Error message
 */
char *error_fetch_cd(datashel *dtsh)
{
	int len, length_id;
	char *errorm, *vr_str, *text;

	vr_str = aux_itoa(dtsh->count);
	if (dtsh->args[1][0] == '-')
	{
		text = ": foreign option ";
		length_id = 2;
	}

	else
	{
		text = ": can't cd to ";
		length_id = strlen(dtsh->args[1]);
	}

	len = strlen(dtsh->agv[0]) + strlen(dtsh->args[0]);
	len += strlen(vr_str) + strlen(text) + length_id + 5;
	errorm = malloc(sizeof(char) * (len + 1));

	if (errorm == 0)
	{
		free(vr_str);
		return (NULL);
	}

	errorm = strcat_cd(dtsh, text, errorm, vr_str);

	free(vr_str);

	return (errorm);
}

/**
 * error_not_found -  error message displayed
 * when command not found
 * @dtsh: data relevant
 * Return: Error message
 */
char *error_not_found(datashel *dtsh)
{
	int len;
	char *errorm;
	char *vr_str;

	vr_str = aux_itoa(dtsh->count);
	len = strlen(dtsh->agv[0]) + strlen(vr_str);
	len += strlen(dtsh->args[0]) + 16;
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
	strcat(errorm, ": not found\n");
	strcat(errorm, "\0");
	free(vr_str);
	return (errorm);
}
