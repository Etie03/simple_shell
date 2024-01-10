#include "shell.h"

/**
 * parac - a function that create parent and child
 * @arry: the array
 * @envp: enviroment pointer
 *
 * Return: always 0
 */

int parac(char **arry, char **envp)
{
	int m;
	pid_t pid;

	switch (pid = fork())
	{
		case -1:
			perror("Error");
			return (-1);
		case 0:
			execve(arry[0], arry, envp);
			break;
		default:
			do {
				waitpid(pid, &m, WUNTRACED);
			} while (WIFEXITED(m) == 0 && WIFSIGNALED(m) == 0);
	}
return (0);
}

/**
 * path_check - a function that checks if the command is found in the path
 * @arr_words: array
 * @e_path: the path
 *
 * Return: return 1 if succes else return 0
 */

int path_check(char **arr_words, char *e_path)
{
	int flag = 0, len_tok, idx = 0, len_arr;
	unsigned int new_size, old_size;
	char **cat_words;
	struct stat find_command;

	flag = 0;
	cat_words = string_extract(e_path, ":");
	len_arr = _strlen(arr_words[0]);
	while (cat_words[idx])
	{
		len_tok = _strlen(cat_words[idx]) + 2;
		new_size = (sizeof(char) * (len_tok + len_arr));
		old_size = (_strlen(cat_words[idx]) + 1);
		cat_words[idx] = _realloc_mem(cat_words[idx], old_size, new_size);
		if (!cat_words)
			return (0);
		_strcat(cat_words[idx], "/");
		_strcat(cat_words[idx], arr_words[0]);
		if (stat(cat_words[idx], &find_command) == 0)
		{
			arr_words[0] = _realloc_mem(arr_words[0], (len_arr + 1), new_size);
			if (!arr_words[0])
				return (0);
			_strcpy(arr_words[0], cat_words[idx]);
			flag = 1;
			break;
		}
		idx++;
	}
	free_func(cat_words);
	return (flag);
}
