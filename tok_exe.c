#include "shell.h"
/**
 *_tok_exec - tokenizes the initial string and execute it
 *
 *@buffer: Initial string captured for getline
 *@name: function name
 *@num: times that the principal function has been executed
 */
void _tok_exec(char *buffer, char *name, int num)
{
	char *tok[2], *aux, *temp, *er = "";
	int i = 0, ex;
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		exit(0);
	}
	else if (pid == 0)
	{
		if (buffer[0] == '\n')
		{ free(buffer), exit(0); }
		tok[i] = strtok(buffer, " \t\n");
		if (tok[0] == NULL)
		{free(buffer), free(tok[0]), exit(0); }
		temp = tok[0];
		while (tok[i] != NULL)
		{i++,   tok[i] = strtok(NULL, " \t\n"); }
		if (_strcmp("env", buffer) == 0)
		{free(buffer), _env(i), free_grid(tok, i), exit(0); }
		er = "F";
		aux = _path(temp);
		if (aux[0] == er[0])
		{free(aux), _error(name, tok[0], num);
			free(buffer), free_grid(tok, i), exit(0); }
		else
			tok[0] = aux;
		ex = execve(tok[0], tok, environ);
		if (ex == -1)
		{_error(name, tok[0], num), free_grid(tok, i), exit(0);
		}
	}
	else
	{
		pid = waitpid(pid, 0, 0);
	}

}
