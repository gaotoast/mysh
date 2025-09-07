#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAXLINE 1024
#define MAXARGS 64

/**
 * コマンドライン入力を受け取る関数
 * @param line 入力を格納するバッファ
 * @return 成功時1、EOF時0
 */
int	read_line(char *line) {
	printf("mysh$ ");

	if (fgets(line, MAXLINE, stdin) == NULL)
		return (0);

	line[strcspn(line, "\n")] = '\0';
	return (1);
}

/**
 * コマンドライン文字列を解析して引数配列に分割する関数
 * @param line 解析する文字列
 * @param argv 引数を格納する配列
 * @return 引数の数
 */
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

/**
 * コマンドを実行する関数
 * @param argv コマンドと引数の配列
 */
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

/**
 * メイン関数 - シェルの主要ループ
 */
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
