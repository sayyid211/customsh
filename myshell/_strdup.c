#include "_shell.c"

/**
 * _strdup - duplicates a string
 * @s: given str
 * Return: pointer to duplicate
 */

char *_strdup(char *s)
{
	char *str;
	int len = 0, i;

	if (!s)
		return (NULL);

	while (s[len] != '\0')
		len++;

	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);

	for (i = 0; s[i] != '\0'; i++)
	{
		str[i] = s[i];
	}
	str[i] = '\0';
	return (str);
}
