#include "main.h"

/**
 * copy_info - function that copies info to create a new env or alias
 * @name: name
 * @value: valu
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _str_len(name);
	len_value = _str_len(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * len);
	_str_spn(new, name);
	_str_cat(new, "=");
	_str_cat(new, value);
	_str_cat(new, "\0");

	return (new);
}

/**
 * set_env - sets an env variable
 * @name: name of the env variable
 * @value: value of the env variable
 * @dtsh: data structure
 * Return: void
 */
void set_env(char *name, char *value, datashel *dtsh)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; dtsh->_environ[i]; i++)
	{
		var_env = _str_dup(dtsh->_environ[i]);
		name_env = _str_tok(var_env, "=");

		if (_str_cmp(name_env, name) == 0)
		{
			free(dtsh->_environ[i]);
			dtsh->_environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}

		free(var_env);
	}

	dtsh->_environ = _realocdp(dtsh->_environ, i, sizeof(char *) * (i + 2));
	dtsh->_environ[i] = copy_info(name, value);
	dtsh->_environ[i + 1] = NULL;
}
