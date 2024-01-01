#include "main.h"

/**
 * cd_dirt - function  that changes to the parent directory
 * @dtsh: data relevant
 */
void cd_dirt(datashel *dtsh)
{
	char pwd[PATH_MAX];
	char *drt, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);
	set_env("OLDPWD", cp_pwd, dtsh);
	drt = dtsh->args[1];
	if (_strcmp(".", drt) == 0)
	{
		set_env("PWD", cp_pwd, dtsh);
		free(cp_pwd);
		return;
	k}

	if (_strcmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	rev_string(cp_strtok_pwd);
	cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _strtok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env("PWD", cp_strtok_pwd, dtsh);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", dtsh);
	}
	dtsh->status = 0;
	free(cp_pwd);
}
