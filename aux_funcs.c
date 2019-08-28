#include "shell.h"
/**
 *_env - print the environ variables
 *
 *@cont: the numers of arguments received for the getline
 *
 *Return: if the function fails: -1, else 0;
 */
int _env(int cont)
{
	int i = 0;

	if (cont > 1)
	{
		perror("Error");
		return (-1);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 *_error - print message error when the functions fails
 *
 *@name: name of program
 *@comand: name of comand that fails
 *@num: number of execution of principal function
 */
void _error(char *name, char *comand, int num)
{
	char *aux = NULL;

	write(2, name, _strlen(name));
	write(2, ": ", 2);
	aux = _convert_num(num);
	write(2, aux, _strlen(aux));
	free(aux);
	write(2, ": ", 2);
	write(2, comand, _strlen(comand));
	write(2, ": not found\n", 12);
}
/**
 *_convert_num - prints int numbers
 *
 *@k: number to print
 *
 *Return: the number of bytes
 */
char *_convert_num(int k)
{
	int a = 1, j = 0;
	char *aux;

	while (k / a > 9)
	{
		a *= 10;
		j++;
	}
	aux = calloc(j + 1, sizeof(char));

	while (a != 0 && j >= 0)
	{
		aux[j] = k / a + '0';
		k = k % a;
		a = a / 10;
		j--;
	}

return (aux);
}
/**
 *_calloc - function allocates memory for an array of nmemb elements
 * of size bytes each and returns a pointer to the allocated memory.
 *@nmemb: amount of elements
 *@size: bytes
 *Return: p pointer allocated with nmemb x size with 0 set values
 *
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size) ; i++)
	{
		p[i] = '\0'; /* anologous for char set values */
	}

return ((void *)p);
}
/**
 *free_grid - function that frees a 2 dimensional grid
 *@grid: grid to free
 *@height: number of row
 */
void free_grid(char **grid, int height)
{
	int cont = 0;

	if (grid != NULL || height > 1)
	{
		while (cont < height)
		{
			free(grid[cont]);
			cont++;
		}
	}
}
