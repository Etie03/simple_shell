#include "shell.h"
/**
 * main- entry point
 *
 * Return: 0
 */

int main(void)
{
	char buffer[BUFFER_SIZE];
	pid_t pid;

	while (1)
	{
		printf("($) ");
		fflush(stdout);

		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			printf("\nExiting shell...\n");
			break;
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, "exit") == 0)
		{
			printf("Exiting shell...\n");
			break;
		}

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{

			if (execlp(buffer, buffer, NULL) == -1)
			{
				perror("execlp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
