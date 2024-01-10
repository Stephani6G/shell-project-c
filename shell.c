#include "main.h"

void execute_command(datashel *dtsh) {
	pid_t pid = fork();

	if (pid == -1) {
		perror("fork");
	} else if (pid == 0) {
		// Child process
		if (execvp(dtsh->args[0], dtsh->args) == -1) {
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	} else {
		// Parent process
		wait(NULL);
	}
}

void parse_input(datashel *dtsh) {
	int i = 0;
	char *token = strtok(dtsh->input, " \t\r\n\a");

	while (token != NULL && i < TOK_BUFSIZE - 1) {
		dtsh->args[i++] = token;
		token = strtok(NULL, " \t\r\n\a");
	}

	dtsh->args[i] = NULL; // Set the last element to NULL for execvp
}

int main(void) {
	datashel dtsh;
	dtsh.input = "/bin/ls -l";
	dtsh.args = malloc(TOK_BUFSIZE * sizeof(char *));
	dtsh.agv = NULL; // You might need to adjust this based on your requirements

	parse_input(&dtsh);

	if (dtsh.args[0] != NULL) {
		execute_command(&dtsh);
	}

	// Free allocated memory
	free(dtsh.args);

	return (0);
}
