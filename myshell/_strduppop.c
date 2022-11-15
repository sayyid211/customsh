#include "_shell.h"

/**
 * _strduppop - duplicates str
 * @s: given str
 * Return: pointer to dup
 */

char *_strduppop(char *s)
{
	char *str;
	int len = 0, i;

	if (!s)
		return (NULL);

	while (s[len] != '\0')
		len++;

	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);

	for (i = 0; s[i] != '\0'; i++)
	{
		str[i] = s[i];
	}
	str[i] = ' ';
	str[i + 1] = '\0';
	return (str);
}
