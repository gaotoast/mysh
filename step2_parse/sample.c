#include <stdio.h>
#include <string.h>

#define MAXLINE 1024
#define MAXARGS 64

/**
 * コマンドライン入力を受け取る関数
 * @param line 入力を格納するバッファ
 * @return 成功時1、EOF時0
 */
int read_line(char *line) {
  printf("mysh$ ");

  if (fgets(line, MAXLINE, stdin) == NULL)
    return 0;

  line[strcspn(line, "\n")] = '\0';
  return 1;
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
	return argc;
}

/**
 * メイン関数 - シェルの主要ループ
 */
int main() {
  char line[MAXLINE];
  char *argv[MAXARGS];

  while (1) {
    if (read_line(line) == 0)
      break;

    int argc = parse_line(line, argv);
    printf("コマンド: %s (引数 %d個)\n", argv[0], argc);
  }
  return 0;
}
