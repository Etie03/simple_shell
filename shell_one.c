#include "shell.h"

/**
 * main - a function that evaluates an input and proccess an output
 * @argc: argument counter
 * @argv: arguments vector
 * @envp: enviroment array
 *
 * Return: 0
 */

int main(int argc, char **argv, char **envp)
{
	char *buff = NULL;
	size_t buff_s = 0;
	ssize_t prt = 1;
	int m = 0;

	(void)argc;
	(void)argv;

	while (prt > 0)
	{
		signal(SIGINT, sign_handlr);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		prt = getline(&buff, &buff_s, stdin);
		if (prt == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		m = string_words(buff);
		if (m > 0)
			func_test(buff, envp);
	}
	free(buff);
	return (0);
}
