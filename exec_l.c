#include "main.h"

/**
 * exec_line - finds builtins and commands
 * @dtsh: relevant data
 * Return: 1 on success
 */
int exec_line(datashel *dtsh)
{
	int (*builtin)(datashel *dtsh);

	if (dtsh->args[0] == NULL)
		return (1);

	builtin = builtin(dtsh->args[0]);

	if (builtin != NULL)
		return (builtin(dtsh));

	return (cmd_exec(dtsh));
}
