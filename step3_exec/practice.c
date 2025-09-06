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

	/* TODO: fork を使ってプロセスを作成する。結果をpid_t型の変数pidに格納する */

	if (pid < 0) {
		perror("fork");
		return ;
	}

	if (pid == 0) {          
		/* TODO: execvp を使ってコマンドを実行する。argv[0]にコマンド名、argvに引数の配列を指定する */
    
		perror("exec");
		exit(1);
	}

  /* TODO: wait を使って子プロセスの終了を待つ */
  /* ヒント: wait の引数は NULL にする*/
  
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
