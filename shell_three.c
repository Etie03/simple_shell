#include "shell.h"

/**
 * sign_handlr -a function  for SIGINT change
 * @sign: value for SIGINT
 *
 */

void sign_handlr(int sign)
{
	if (sign == SIGINT)
	write(STDOUT_FILENO, "\n($) ", 5);
}

/**
 * find_path - a function that finds the PATH
 * @envp: environment pointer
 *
 * Return: pointer to PATH
 */

char *find_path(char **envp)
{
	int m = 0;
	char *envi = NULL;

	while (envp[m])
	{
		if (!_strncmp("PATH", envp[m], 4))
			envi = envp[m] + 5;
		m++;
	}
	return (envi);
}

/**
 * _strcmp - a function that compares two strings
 * @s1: first value
 *@s2: second value
 *
 * Return: 0 if equal else return an integer
 */
int _strcmp(char *s1, char *s2)
{
	int m = 0, g = 0, l, f = 0;

	while (s1[m] != 0)
	{
		m++;
	}
	while (s2[g] != 0)
	{
		g++;
	}
	for (l = 0; l <= m && l <= g; l++)
	{
		if (s1[l] != s2[l])
		{
			f = (s1[l] - '0') - (s2[l] - '0');
			break;
		}
	}
	return (f);
}

/**
 * find_env - function to find the PATH
 * @envp: environment pointer
 *
 */

void find_env(char **envp)
{
	int m = 0;

	while (envp[m])
	{
		write(STDOUT_FILENO, envp[m], _strlen(envp[m]));
		write(STDOUT_FILENO, "\n", 1);
		m++;
	}
}

/**
 * free_func - a function to free pointer
 * @double_pointer: pointer to pointer
 *
 */

void free_func(char **double_pointer)
{
	char **temp = double_pointer;

	if (!double_pointer)
		return;
	while (*double_pointer)
		free(*double_pointer++);
	free(temp);
}
