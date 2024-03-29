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
 * struct line_list_singly - singly linked list
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
	int length_val;
	struct r_var_lists *next;
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
char *_str_cat(char *dest, const char *src);
int _str_cmp(char *s1, char *s2);
char *_str_chr(char *str, char c);
int _str_spn(char *str, char *accept);


/* strin_2.c */
char *_str_dup(const char *str);
int _str_len(const char *str);
int cmpr_char(char str[], const char *dlm);


char *_str_tok(char str[], const char *dlm);
int _is_digit(const char *str);

/* stri_4. c */
void rev_string(char *str);

int cd_shel(datashel *dtsh);
/* chekr.c */
int repeat_chars(char *inputs, int index);
int err_sep(char *inputs, int index, char last);
int find_first_char(char *inputs, int *index);
void print_syntx_err(datashel *dtsh, char *inputs, int index, int bool);
int check_syntx_err(datashel *dtsh, char *inputs);

/*sl1t.c */
char *swapd_chars(char *inputs, int bool);

/* sl2t.c */
void addnode(sep_l **head_s, line_l **head_l, char *inputs);


/* sl3t.c */
void go_to_next(sep_l **list_s, line_l **list_l, datashel *dtsh);

/* sl4t.c */
int split_coms(datashel *dtsh, char *inputs);

/* sl5t.c */
char **split_line(char *inputs);

/* l1st.c*/
sep_l *add_sep_node_end(sep_l **head, char sept);

/* l2st.c*/
void free_sep_list(sep_l **head);
line_l *add_line_node_end(line_l **head, char *line);
void free_line_list(line_l **head);

/* l3st.c */
r_vars *add_var_nodes(r_vars **head, int lvar, char *val, int lval);

/* l4st.h */
void free_rvar_list(r_vars **head);

/* loop.c */
char *remove_comment(char *in);
void shell_looped(datashel *dtsh);

/* varenv */
void check_env(r_vars **h, char *in, datashel *data);
int check_vars(r_vars **h, char *in, char *st, datashel *data);
/* var2env */
char *replace_input(r_vars **head, char *inputs, char *new_input, int nlen);
char *rep_var(char *inputs, datashel *dtsh);

/* readlin */
char *readlin(int *i_eof);
/* main.c */
void frees_data(datashel *dtsh);
void sets_data(datashel *dtsh, char **agv);
int mains(int ac, char **agv);

/*signal.c */
void get_ssigint(int sign);

/* bufline */
void buf_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t gets_line(char **lineptr, size_t *n, FILE *stream);
/* help.c */
int get_help(datashel *dtsh);

/* fixerr.c */
int get_error(datashel *dtsh, int eval);
/* exitsh */
int exit_shell(datashel *dtsh);

/* exec_l.c */
int exec_line(datashel *dtsh);

/* environ.c */
int cmp_env_name(const char *nenv, const char *name);
char *_getenv(const char *name, char **_environ);
int _env(datashel *dtsh);

/* en2ron.c */
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, datashel *dtsh);
/* en3rin */
int _setenv(datashel *dtsh);
int _unsetenv(datashel *dtsh);


#endif
