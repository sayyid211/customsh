#include "_shell.h"

/**
 * check_builtin - checks if a token is a built in
 * @tk: tokens entered
 * @status: built in or custom
 * @env: environ variable
 */

void check_builtin(char **tk, char **env__attribute__((unused)), int *status)
{
	int i;

	if (_strcmp(tk[0], "exit") == 0)
	{
		printf("Entered exit\n");
		(*status) = 0;
		free(tk);
		exit(0);
	}
	else if (_strcmp(tk[0], "env") == 0)
	{
		printf("Entered env\n");
		(*status) = 0;
		i = 0;
		while (env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
	}
	else
	{
		add_path(tk, env, status);
	}
}
