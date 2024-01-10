#include "shell.h"

/**
 * string_words- a function that counts the words in the string
 * @str: string
 *
 * Return: the number of words
 */

int string_words(char *str)
{
	int m;
	int cont = 0;
	int st = 0;

	for (m = 0; str[m] != '\0'; m++)
	{
		if (str[m] == ' ' || str[m] == '\n' || str[m] == '\t' || str[m] == ':')
			st = 0;
		else if (st == 0)
		{
			st = 1;
			cont++;
		}
	}
	return (cont);
}

/**
  * string_extract - a function that extract tokens from strings
  * @str: string to token
  * @delim: to separate words
  *
  * Return: array with tokenized words
  */

char **string_extract(char *str, char *delim)
{
	char **words = NULL, *token, *buff;
	int m = 0, aux = 0, word_count = 0, j = 0;

	while (str[j])
	{
		if (str[j] == '\n')
			str[j] = '\0';
		j++;
	}

	word_count = string_words(str);
	buff = malloc(sizeof(char) * (_strlen(str) + 1));
	if (!buff)
		return (NULL);
	words = malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	_strcpy(buff, str);
	token = strtok(buff, delim);

	while (token)
	{
		words[m] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (!words[m])
		{
			for (aux = m; aux >= 0; aux--)
				free(words[aux]);
			free(words);
			return (NULL);
		}
		_strcpy(words[m], token);
		token = strtok(NULL, delim);
		m++;
	}
	words[m] = NULL;
	free(buff);
	return (words);
}

/**
 * func_test - test the array and choose the correct function to use
 * @buffer: string with commands send by console
 * @envp: enviroment
 *
 */

void func_test(char *buffer, char **envp)
{
	int flag = 0;
	char **array_words, *e_path = NULL;
	struct stat find_command;

	e_path = find_path(envp);
	array_words = string_extract(buffer, " \t");
	if (array_words[0] == NULL)
		perror("./hsh");
	else if (!(_strcmp(array_words[0], "exit")))
		flag = func_exit(array_words, buffer);
	else if (!(_strcmp(array_words[0], "env")))
	{
		find_env(envp);
		flag = 2;
	}
	if (array_words[0][0] != '/' && flag == 0)
		flag = path_check(array_words, e_path);
	if (flag == 0)
	{
		if (stat(array_words[0], &find_command) == 0)
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		if (access(array_words[0], X_OK) == 0)
			parac(array_words, envp);
		else
			perror("./hsh");

	}
	if (flag == 0)
		perror("./hsh");
	free_func(array_words);
}

/**
 * _atoi - a function that converts string to int
 *@stg: string to convert
 *
 * Return: integer converted
 */
int _atoi(char *stg)
{
	unsigned int soln = 0;
	int m = 0, j = 0, a = 0, ngt = 1;

	while (stg[m] != '\0')
	{
		m++;
	}
	for (j = 0; j < m; j++)
	{
		if (stg[j] == '-')
			ngt = ngt * -1;
		while ((stg[j] >= '0') && (stg[j] <= '9'))
		{
			soln = (soln * 10) + (stg[j] - '0');
			j++;
			a = 1;
		}
		if (a == 1)
			j = m;
	}
	soln = soln * ngt;
	return (soln);
}

/**
 * func_exit - a function to exit the shell
 * @array_words: string with tokens
 * @buffer: buffer from the getline
 *
 * Return: 2 if the argument of exit is error
 */

int func_exit(char **array_words, char *buffer)
{
	unsigned int arg_exit = 0;
	int len_exit = 0, flag = 0;

	if (array_words[1] == NULL || (!_strcmp(array_words[1], "0")))
	{
		free_func(array_words);
		free(buffer);
		exit(0);
	}
	arg_exit = _atoi(array_words[1]);
	if (arg_exit > 0)
	{
		free_func(array_words);
		free(buffer);
		exit(arg_exit);
	}
	else
	{
		len_exit = _strlen(array_words[1]);
		write(STDOUT_FILENO, "exit: Illegal number: ", 22);
		write(STDOUT_FILENO, array_words[1], len_exit);
		write(STDOUT_FILENO, "\n", 1);
		flag = 2;
	}
	return (flag);
}
