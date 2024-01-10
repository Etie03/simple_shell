#include "shell.h"
/**
 * executeCommand - Executes the given command using execlp
 * @command: The command to execute
 */

void executeCommand(char *command)
{
	if (execlp(command, command, NULL) == -1)
	{
		perror("execlp");
		exit(EXIT_FAILURE);
	}
}
/**
 * runShell - Runs the shell program.
 */
void runShell(void)
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

			executeCommand(buffer);
		}
		else
		{
			wait(NULL);
		}
	}
}
/**
 * main - entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
	runShell();
	return (0);
}
