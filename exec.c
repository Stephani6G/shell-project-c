#include "main.h"

/**
 * is_direc - checks ":" if is in the current directory
 * @path: type char pointer char
 * @index: type int pointer of inde
 * Return: 1 if the path is searchable in the cd, 0 otherwise
 */
int is_direc(char *path, int *index)
{
	if (path[*index] == ':')
		return (1);

	while (path[*index] != ':' && path[*index])
	{
		*index += 1;
	}

	if (path[*index])
		*index += 1;

	return (0);
}

/**
 * _where_com - function that locates a command
 * @cmd: command name
 * @_environ: environment variable
 * Return: location of the command
 */
char *_where_com(char *cmd, char **_environ)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

	path = getenv("PATH", _environ);
	if (path)
	{
		ptr_path = _str_dup(path);
		len_cmd = _str_len(cmd);
		token_path = _str_tok(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (is_cdir(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _strlen(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			_str_spn(dir, token_path);
			_str_cat(dir, "/");
			_str_cat(dir, cmd);
			_str_cat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = _str_tok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}
/**
 * is_exec - determines if is an executable
 * @dtsh: data structure
 * Return: 0 if is not an executable, other number if it does
 */
int is_exec(datashel *dtsh)
{
	struct stat st;
	int i;
	char *input;

	input = dtsh->args[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(input + i, &st) == 0)
	{
		return (i);
	}
	path_error(dtsh, 127);
	return (-1);
}

/**
 * check_err_perm - verifies if user has permissions to access
 * @dir: destination directory
 * @dtsh: data structure
 * Return: 1 if there is an error, 0 if not
 */
int check_err_perm(char *dir, datashel *dtsh)
{
	if (dir == NULL)
	{
		path_error(dtsh, 127);
		return (1);
	}

	if (_str_cmp(dtsh->args[0], dir) != 0)
	
	{
		if (access(dir, X_OK) == -1)
		{
			path_error(dtsh, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(dtsh->args[0], X_OK) == -1)
		{
			path_error(dtsh, 126);
			return (1);
		}
	}

	return (0);
}
/**
 * cmd_exec - executes command lines
 * @dtsh: data relevant
 * Return: 1 on success
 */
int cmd_exec(datashel *dtsh)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_executable(dtsh);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which(dtsh->args[0], dtsh->_environ);
		if (check_err_perm(dir, dtsh) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which(dtsh->args[0], dtsh->_environ);
		else
			dir = dtsh->args[0];
		execve(dir + exec, dtsh->args, dtsh->_environ);
	}
	else if (pd < 0)
	{
		perror(dtsh->agv[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	dtsh->status = state / 256;
	return (1);
}
