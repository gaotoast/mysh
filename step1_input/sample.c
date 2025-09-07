#include <stdio.h>
#include <string.h>

#define MAXLINE 1024

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
 * メイン関数 - シェルの主要ループ
 */
int main() {
  char line[MAXLINE];

  while (1) {
    if (read_line(line) == 0)
      break;

    printf("入力: %s\n", line);
  }
  return 0;
}
