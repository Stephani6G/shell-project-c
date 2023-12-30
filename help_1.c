#include "main.h"

/**
 * help_environ - Help information for the builtin environ
 */
void help_environ(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, strlen(help));
	help = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, help, strlen(help));
}
/**
 * help_setenv - Help information for the builtin setenv
 */
void help_setenv(void)
{

	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, strlen(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, strlen(help));
	help = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, help, strlen(help));
}
/**
 * help_unsetenv - Help information for the builtin unsetenv
 */
void help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, strlen(help));
	help = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, help, strlen(help));
}


/**
 * help_general - Entry point for help
 *information for the help builtin
 */
void help_general(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, strlen(help));
	help = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, help, strlen(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help, strlen(help));
	help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, strlen(help));
	help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help, strlen(help));
	help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, strlen(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, strlen(help));
}
