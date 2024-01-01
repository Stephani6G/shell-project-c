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

extern char **environ;
char *aux_itoa(int n);

/* fizzbuzz */
int main(void);
int _putchar(char c);

/**
 * struct datas - struct that contains
 * all relevant data on runtime
 * @agv: the argument vector of the commands
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @count: lines counter
 * @_environ: environment variable of the shell
 * @piid: the  process ID of the simkple shell
 */
typedef struct datas
{
	char **agv;
	char *input;
	char **args;
	int status;
	int count;
	char **_environ;
	char *piid;
} datashel;

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


/**
 * struct sep_list - a  singly linked list
 * @sep: ; | &
 * @next: next node in the linked list
 * Description: singly linked list to store separators
 */
typedef struct sep_list
{
	char sep;
	struct sep_list *next;
} sep_l;

/**
 * struct r_var_lists - single linked list
 * @length_var: length of the variable
 * @value: value of the variable
 * @length_val: length of the value var
 * @next: next node i as singly linked list
 * Description: single linked list to store variables
 */
typedef struct r_var_lists
{
	int length_var;
	char *value;
	int length_value;
	struct r_vasr_lists *next;
} r_vars;
/* err_1.c */
char *strcat_cd(datashel *dtsh, char *text, char *errorm, char *vr_str);

/* err_2.c */
char *error_fetch_cd(datashel *dtsh);
char *error_not_found(datashel *dtsh);
char *aux_itoa(int n);


/* err_3.c */
char *error_shell_exit_shell(datashel *dtsh);

/* a_err_1.c */
char *err_env(datashel *dtsh);
char *path_error(datashel *dtsh);

/* help_1.c */
void help_environ(void);
void help_setenv(void);
void help_unsetenv(void);
void help_general(void);
void help_exit(void);

/* help-2.c */
void help_b(void);
void help_alias(void);
void help_cd(void);


/* memory.c */
void _memcpy(void *newpointer, const void *pointer, unsigned int size);
void *_realloc(void *pointer, unsigned int old_size, unsigned int new_size);
char **_realocdp(char **pointer, unsigned int old_size, unsigned int new_size);
/* stdlib.c */
int get_length(int n);
char *aux_itoa(int n);
int _atoi(char *str);

/* strin_1.c */
char _str_cat(char *dest, const char *src);
char _str_cpy(char *dest, char *src);
int _str_cmp(char *s1, char *s2);
char _str_chr(char *str, char c);
int _str_spn(char *str, char *accept);

#endif
