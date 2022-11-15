#include "_shell.h"

/**
 * tokstr - tokenize string
 *
 * @str: string to tokenize
 * @type: path(1) or command (0)
 * Return: pointer to array of tokens
 */

char **tokstr(char *str, int type)
{
	int i, length = 1, count = 0;
	char *s = NULL, *token = NULL, **tk = NULL;
	if (type == 1)
		s = _strdup(str);
	else if (type == 0)
		s = _strduppop(str);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i} == ' ' && type == 0)
			length++;
		else if (str[i] == ':' && type == 1)
			length++;
	}
	if (type == 1)
		strtok(s, "=");
	tk = malloc(sizeof(char *) * length);
	if (type == 0)
		token = strtok(s, " \t\r\n\v\f\0 ");
	else if (type == 1)
		token = strtok(NULL, ":");
	while (token)
	{
		tk[count] = _strdup(token);
		if (type == 0)
			token = strtok(NULL, " \t\r\n\v\f\0 ");
		else if (type == 1)
			token = strtok(NULL, ":");
		count++;
	}
	tk[count] = token;
	free(s);
	return (tk);
}
