#include "main.h"

/**
 * cd_dot - changes to the parent directory
 * @dtsh: data relevant
 * Return: no return success aways
 */
void cd_dot(datashel *dtsh)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _str_dup(pwd);
	setenv("OLDPWD", cp_pwd, datashel);
	dir = dtsh->args[1];
	if (_str_cmp(".", dir) == 0)
	{
		setenv("PWD", cp_pwd, datashel);
		free(cp_pwd);
		return;
	}
	if (_str_cmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	rev_string(cp_strtok_pwd);
	cp_strtok_pwd = _str_tok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _str_tok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		setenv("PWD", cp_strtok_pwd, dtsh);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", dtsh);
	}
	dtsh->status = 0;
	free(cp_pwd);
}

/**
 * cd_to - changes to a directory given
 * by the user
 * @dtsh: data relevant
 * Return: no return success always
 */
void cd_to(datashel *dtsh)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	dir = dtsh->args[1];
	if (chdir(dir) == -1)
	{
		path_error(dtsh, 2);
		return;
	}

	cp_pwd = _str_dup(pwd);
	set_env("OLDPWD", cp_pwd, dtsh);

	cp_dir = _strdup(dir);
	set_env("PWD", cp_dir, dtsh);

	free(cp_pwd);
	free(cp_dir);

	dtsh->status = 0;

	chdir(dir);
}
/**
 * cd_previous - changes to the previous directory
 * @dtsh: data relevant
 * Return: no return success always
 */
void cd_previous(datashel *dtsh)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);

	p_oldpwd = getenv("OLDPWD", dtsh->_environ);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = _strdup(p_oldpwd);

	set_env("OLDPWD", cp_pwd, dtsh);

	if (chdir(cp_oldpwd) == -1)
		set_env("PWD", cp_pwd, dtsh);
	else
		set_env("PWD", cp_oldpwd, dtsh);

	p_pwd = _getenv("PWD", dtsh->_environ);

	write(STDOUT_FILENO, p_pwd, _str_len(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	dtsh->status = 0;

	chdir(p_pwd);
}

/**
 * cd_to_home - changes to home directory
 * @dtsh: data relevant
 * Return: no return success always
 */
void cd_to_home(datashel *dtsh)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup(pwd);

	home = _getenv("HOME", dtsh->_environ);

	if (home == NULL)
	{
		set_env("OLDPWD", p_pwd, dtsh);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		get_error(dtsh, 2);
		free(p_pwd);
		return;
	}

	set_env("OLDPWD", p_pwd, dtsh);
	set_env("PWD", home, dtsh);
	free(p_pwd);
	dtsh->status = 0;
}
