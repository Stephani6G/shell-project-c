#include "main'h"

/**
 * _setenv - compares env variables names with the name passed
 * @dtsh: relevant data
 * Return: 1 on success
 */
int _setenv(datashel *dtsh)
{
	if (dtsh->args[1] == NULL || dtsh->args[2] == NULL)
	{
		get_error(dtsh, -1);
		return (1);
	}

	set_env(dtsh->args[1], dtsh->args[2], dtsh);

	return (1);
}

/**
 * _unsetenv - deletes env variable
 * @dtsh: relevant data
 * Return: 1 on success
 */
int _unsetenv(datashel *dtsh)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (dtsh->args[1] == NULL)
	{
		get_error(dtsh, -1);
		return (1);
	}

	k = -1;
	for (i = 0; dtsh->_environ[i]; i++)
	{
		var_env = _str_dup(dtsh->_environ[i]);
		name_env = _str_tok(var_env, "=");

		if (_str_cmp(name_env, dtsh->args[1]) == 0)
			k = i;

		free(var_env);
	}

	if (k == -1)
	{
		get_error(dtsh, -1);
		return (1);
	}

	realloc_environ = malloc(sizeof(char *) * i);
	for (i = j = 0; dtsh->_environ[i]; i++)
	{
		if (i != k)
			realloc_environ[j++] = dtsh->_environ[i];
	}

	realloc_environ[j] = NULL;
	free(dtsh->_environ[k]);
	free(dtsh->_environ);
	dtsh->_environ = realloc_environ;
	return (1);
}
