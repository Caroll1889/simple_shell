#ifndef _SHELL_H
#define _SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stddef.h>
#define FAIL "FAIL"
#define TRUE 1
#define FALSE 0
#define CRASH -1
#define START 0
#define RUN 1
#define EXIT_SUCCESS 0
extern char **environ;
void _tok_exec(char *buffer, char *name, int num);
char *_path(char *str);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strtok(char *str, char *separator, int flag);
void free_grid(char **grid, int height);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_convert_num(int k);
int _env(int cont);
void _error(char *name, char *comand, int num);
#endif
