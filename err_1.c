#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * strcat_cd - function that concatenates the message for
 * change of directory  error
 * @dtsh: data relevant
 * @text: message to print
 * @errorm: output message
 * @vr_str: counter lines
 * Return: error message
 */
char *strcat_cd(datashel *dtsh, char *text, char *errorm, char *vr_str)
{
	char *wrong_flag;

	strcpy(errorm, dtsh->av[0]);
	strcat(errorm, ": ");
	strcat(errorm, vr_str);
	strcat(errorm, ": ");
	strcat(errorm, dtsh->args[0]);
	strcat(errorm, text);
	if (dtsh->args[1][0] == '-')
	{
		wrong_flag = malloc(3);
		wrong_flag[0] = '-';
		wrong_flag[1] = dtsh->args[1][1];
		wrong_flag[2] = '\0';
		strcat(errorm, wrong_flag);
		free(wrong_flag);
	}

	else
	{
		strcat(errorm, dtsh->args[1]);
	}

	strcat(errorm, "\n");
	strcat(errorm, "\0");
	return (errorm);
}
