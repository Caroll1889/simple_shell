#include "shell.h"
/**
 * handler - function for get signal on ctrl command
 * @num: integer which receives the signal handler
 */
void handler(__attribute__((unused))int num)
{
	signal(SIGINT, handler);
	write(STDOUT_FILENO, "\n", 1);
}
/**
 *main - program for shell runtime
 *@argc: number of arguments
 *@argv: argments
 *Return: EXIT_SUCCESS if sucessful
 */
int main(__attribute__((unused))int argc, char **argv)
{
	char *buffer = NULL, *aux = "exit\n";
	size_t bufsize = 1;
	ssize_t checkgetline = TRUE;
	int num = 0;


	signal(SIGINT, handler);
	while (checkgetline != EOF)
	{
		fflush(stdout);
	num++;
		if (isatty(STDIN_FILENO) == 1)  /* Check for non interactive mode */
			write(1, "$ ", 2);

		checkgetline = getline(&buffer, &bufsize, stdin);
		if (checkgetline == EOF)
		{
			break;
		}
		if (_strcmp(buffer, aux) == 0)
		{
			free(buffer);
			exit(0);
		}
		_tok_exec(buffer, argv[0], num);
	}
	free(buffer);
	return (EXIT_SUCCESS);
}
