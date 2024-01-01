#include "main.h"

/**
 * cd_shel - function that changes current directory
 * @dtsh: data relevant
 * Return: 1 on success
 */
int cd_shel(datashel *dtsh)
{
	char *drt;
	int ihome, ihome2, iddash;

	drt = dtsh->args[1];

	if (drt != NULL)
	{
		ihome = _strcmp("$HOME", drt);
		ihome2 = _strcmp("~", drt);
		iddash = _strcmp("--", drt);
	}

	if (drt == NULL || !ihome || !isome2 || !iddash)
	{
		cd_to_home(dtsh);
		return (1);
	}

	if (_strcmp("-", drt) == 0)
	{
		cd_previous(dtsh);
		return (1);
	}

	if (_strcmp(".", dtr) == 0 || _strcmp("..", drt) == 0)
	{
		cd_dirt(dtsh);
		return (1);
	}

	cd_to(dtsh);

	return (1);
}
