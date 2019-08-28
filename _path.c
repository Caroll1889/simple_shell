 #include "shell.h"
/**
 *_path -function that searchs the route and concatenate
 * the argument in str
 * @str: firts argument from the getline
 * Return: the argument with the route, if the comand don't exist then F
 */
char *_path(char *str)
{
	char *name = "PATH", *tok, *temp, *s = "/";
	int i;


	if (access(str, X_OK) == 0)
		return (str);  /* str is a correct path route*/
	str = str_concat(s, str);
	for (i = 0; environ[i] != NULL; i++)
	{
		tok = _strtok(environ[i], "=", START);
		if (_strcmp(name, tok) == 0)
		{
			temp = str_concat(tok, str);
			if (access(temp, X_OK) == 0)
			{
				free(tok);
				free(str);
				return (temp);
			}
			while (tok != NULL)
			{
				free(tok);
				tok = _strtok(environ[i], "=:", RUN);
				free(temp);
				temp = str_concat(tok, str);
				if (access(temp, X_OK) == 0)
				{
					free(tok);
					free(str);
					return (temp);
				}
			}
			break;
		}
		free(tok);
	}
	free(str);
	temp[0] = 'F';
	return (temp);
}
