#include "_shell.h"

/**
 * add_path - add command path to tokens
 *
 * @cmd: command
 * @env: environ variable
 * @status: set to 0 if cmd is not found
 */

void add_path(char **cmd, char **env, int *status)
{
	char *path;
	char **ppath;
	struct stat buf;
	int i = 0;

	char *_cwd = getcwd(NULL, 0);

	path = find_path(env);
	ppath = tokstr(path, 1);

	(*status) = 0;

	while (ppath[i])
	{
		chdir(ppath[i]);
		if (stat(cmd[0], &buf) == 0)
		{
			(*status) = 1;
			cmd[0] = _strcat(ppath[i], cmd[0]);
			break;
		}
		i++;
	}
	chdir(_cwd);
}
