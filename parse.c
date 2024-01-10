#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 128

void execute_command(char *args[])
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
    }
    else if (pid == 0)
    {
        // Child process
        if (execvp(args[0], args) == -1)
        {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        // Parent process
        wait(NULL);
    }
}

void parse_input(char *input, char *args[])
{
    int i = 0;
    char *token = strtok(input, " \t\r\n\a");

    while (token != NULL && i < MAX_ARGS - 1)
    {
        args[i++] = token;
        token = strtok(NULL, " \t\r\n\a");
    }

    args[i] = NULL; // Set the last element to NULL for execvp
}

int main(void)
{
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARGS];

    while (1)
    {
        printf("$ ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        if (strcmp(input, "exit\n") == 0)
        {
            break;
        }

        parse_input(input, args);

        if (args[0] != NULL)
        {
            execute_command(args);
        }
    }

    return (0);
}
