#include "_shell.h"

/**
 * find_path - finds a path to command and run it
 *
 * @env: environment var
 * Return: pointer to path
 */

char *find_path(char **env)
{
	char *path;

	int i;
	int pi = 0;

	for (i = 0; env[i]; i++)
	{
		if (env[i][0] == 'P' && env[i][1] == 'A'
		    && env[i][2] == 'T' && env[i][3] == 'H')
		{
			pi = i;
			break;
		}
		else
		{
			continue;
		}
	}
	if (pi)
	{
		path = _strdup(env[pi]);
		return (path);
	}
	return (NULL);
}
