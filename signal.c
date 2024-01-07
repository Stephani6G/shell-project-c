#include "main.h"

/**
 * get_ssigint - Handle the ctrl + c call in prompt
 * @sign: signal handler
 */
void get_ssigint(int sign)
{
	(void)sign;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
