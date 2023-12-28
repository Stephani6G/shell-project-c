#include "main.h"

/**
 *envron - a function that prints current environment
 *@token_com: command entered into environ to be parsed
 */

void envron(char **token_com __attribute__((unused)))
{
	int index;

	for (index = 0; envron[index] != NULL; index++)
	{
		print(envron[index], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}



/**
 * wquit -  a command to exit the shell
 * @token_com: command entered
 */

void wquit(char **token_com)
{
	int num_t = 0, arg;

	for (; token_com[num_t] != NULL; num_t++)
		;
	if (num_t == 1)
	{
		free(token_com);
		free(line);
		free(command);
		exit(status);
	}
	else if (num_t == 2)
	{
		arg = _atoi(token_com[1]);
		if (arg == -1)
		{
			print(shell_name, STDERR_FILENO);
			print(": 1: exit: Illegal number: ", STDERR_FILENO);
			print(token_com[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line);
			free(command);
			free(token_com);
			exit(arg);
		}
	}
	else
		print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
