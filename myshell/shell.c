#include "_shell.h"

/**
 * main - Entrypoint (custom shell)
 *
 * @argc: arguments count
 * @argv: arguments vector
 * @env: Eviron variable
 * Return: Success
 */

int main(int argc, char **argv, __attribute__((unused)) char **env)
{
	char **token; /* individual tokens or commands */
	char *line = NULL; /* input string */
	int stats;
	int flag;
	size_t line_cap = 0;
	size_t line_ret = 1;
	pid_t child_pid;

	while (line_ret > 0)
	{
		flag = 1;
		printf("$ ");
		fflush(stdout);
		line_ret = getline(&line, &line_cap, stdin);
		if (line_ret == ULONG_MAX)
			break;
		token = tokstr(line, 0);
		check_builtin(token, env, &flag);
		if (flag == 1)
			child_pid = fork();
		if (child_pid != -1 && flag == 1)
		{
			if (child_pid == 0)
			{
				execve(token[0], token, NULL);
				perror(argv[0]);
				exit(1);
			}
			else
			{
				wait(&stats);
			}
		}
	}
	return (0);
}
