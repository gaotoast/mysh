#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAXLINE 1024
#define MAXARGS 64

int	read_line(char *line) {
	printf("mysh$ ");

	if (fgets(line, MAXLINE, stdin) == NULL)
		return (0);

	line[strcspn(line, "\n")] = '\0';
	return (1);
}

int	parse_line(char *line, char *argv[]) {
	int argc = 0;
	char *token = strtok(line, " ");
	
	while (token != NULL && argc < MAXARGS - 1) {
		argv[argc] = token;
		argc++;
		token = strtok(NULL, " ");
	}

	argv[argc] = NULL;
	return (argc);
}

void	execute(char *argv[]) {
	if (argv[0] == NULL)
		return ;

	pid_t pid = fork();
	if (pid < 0) {
		perror("fork");
		return ;
	}

	if (pid == 0) {          
		execvp(argv[0], argv);
		perror("exec");
		exit(1);
	}

	wait(NULL);
}

int	main() {
	char line[MAXLINE];
	char *argv[MAXARGS];
	
	while (1) {
		if (read_line(line) == 0)
			break;

		int argc = parse_line(line, argv);
		if (argc > 0)
			execute(argv);
	}
	return (0);
}
