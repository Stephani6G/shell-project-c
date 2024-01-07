#include "main.h"

/**
 * frees_data - frees data structure
 * @dtsh: data structure
 */
void frees_data(datashel *dtsh)
{
	unsigned int i;

	for (i = 0; dtsh->_environ[i]; i++)
	{
		free(dtsh->_environ[i]);
	}

	free(dtsh->_environ);
	free(dtsh->piid);
}

/**
 * sets_data - Initialize data structure
 * @dtsh: data structure
 * @agv: argument vector
 */
void sets_data(datashel *dtsh, char **agv)
{
	unsigned int i;
	pid_t piid;

	dtsh->agv = agv;
	dtsh->input = NULL;
	dtsh->args = NULL;
	dtsh->status = 0;
	dtsh->count = 1;

	for (i = 0; environ[i]; i++)
		;

	dtsh->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		dtsh->_environ[i] = _str_dup(environ[i]);
	}

	dtsh->_environ[i] = NULL;
	piid = getpid();
	dtsh->piid = aux_itoa(piid);
}

/**
 * mains - Entry point
 * @ac: argument count
 * @agv: argument vector
 * Return: 0 on success
 */
int mains(int ac, char **agv)
{
	datashel dtsh;
	(void) ac;

	signal(SIGINT, getlogin);
	sets_data(&dtsh, agv);
	shell_looped(&dtsh);
	frees_data(&dtsh);
	if (dtsh.status < 0)
		return (255);
	return (dtsh.status);
}
