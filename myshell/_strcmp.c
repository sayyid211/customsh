#include "_shell.h"

/**
 * _strcmp - compares 2 strings
 * @s1: string a
 * @s2: string b
 * Return: equal(0) less(-1) more(1)
 */
int _strcmp(char *s1, char *s2)
{
	int count = 0, count2 = 0;

	while (count == 0)
	{
		if ((*(s1 + count2) == '\0') && (*(s2 + count2) == '\0'))
			break;
		count = *(s1 + count2) - *(s2 + count2);
		count2++;
	}

	return (count);
}
