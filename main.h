#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>
#include <fcntl.h>
#include <signal.h>
#include <stddef.h>
#include <sys/stat.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"


/* fizzbuzz */
int main(void);
int _putchar(char c);

/**
 * struct builtin_strruc - Builtin struct for command arguments
 * @typen:  name of the command builtin
 * @funcs: data type pointer function.
 */

typedef struct builtin_strruc
{
	char *typen;
	int (*funcs)(datashel *dtsh);
} builtin_typed;


/**
 * struct list_singly - singly linked list
 * @lineui: command line interface
 * @next: next node in a singly linked lists
 * Description: single linked list to store command lines
 */
typedef struct line_list_singly
{
	char *lineui;
	struct line_list_singly *next;
} line_l;



#endif
