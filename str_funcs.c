#include "shell.h"
/**
 **_strtok - function that segments a string according
 * to separtor
 * @str: string to segment by delimiters
 * @delim : separator to delim the string
 * @flag: signal for continue previous process where
 * it was started
 * Return: pointer to string until is the separator
 */
char *_strtok(char *str, char *delim, int signal)
{
	char *tok = NULL;

	int i, j;
	int n = 0, len = 0;
	static int cont;

	cont = (signal == 0) ? 0 : cont;
	if (str == NULL)
		return (NULL);
	for (i = cont; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
				break;
		}
		len++;
	}
	if (len != 0)
		tok = _calloc(len + 1, sizeof(char));
	if (tok == NULL)
		return (NULL);
	for (i = cont; str[i]; i++)
	{
		cont++;
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == ':' && str[i + 1] == ':' && delim[j] == ':')
			{ tok[0] = ':';
				return (tok); }
			if (str[i] == delim[j])
			{tok[n] = '\0';
				return (tok); }
		}
		tok[n] = str[i];
		n++;
	}
	tok[n] = '\0';
	return (tok);
}
/**
 * str_concat - function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter
 * @s1: output with original content of s1 and & with s2
 * @s2: string for concatenate
 * Return: s1 output from s1 + s2
*/
char *str_concat(char *s1, char *s2)
{
	char *s;
	unsigned int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		;
	for (j = 0; s2[j] != '\0'; j++)
		;

	s = malloc(i + j + 1);
	if (s == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		s[i] = s1[i];
	for (j = 0; s2[j] != '\0'; j++)
		s[i + j] = s2[j];

	s[i + j] = '\0';
return (s);
}
/**
 *_strcmp -function that compares 2 strings
 *@s1: input string
 *@s2: input string
 *Return: diff from strings following ASCII
*/
int _strcmp(char *s1, char *s2)
{
while (*s1 != '\0' && *s2 != '\0')
{
	if (*s1 != *s2)
		return (*s1 - *s2);
	s1++;
	s2++;
}
return (0);
}
/**
 *_strlen - function that calculate the lenght
 * of the input string
 *@s: string input
 *Return: lenght of string
*/
int _strlen(char *s)
{
int i;
for (i = 0; s[i] != '\0'; i++)
	;
return (i);
}
