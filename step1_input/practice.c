#include <stdio.h>
#include <string.h>

#define MAXLINE 1024

int read_line(char *line) {
  printf("mysh$ ");

  if (fgets(line, MAXLINE, stdin) == NULL)
    return 0;

  /* TODO: 文字列の最後の改行文字を終端文字に変更する */
  /* ヒント: strcspn は第2引数の文字が最初に現れるインデックスを返す */
  /* 例: strcspn("hello\n", "\n") は 5 を返す */
  line[strcspn(line, "\n")] = ;
  return 1;
}

int main() {
  /* TODO: MAXLINE サイズの文字配列を宣言する */
  /* ヒント: 変数名は line にする */

  while (1) {
    if (read_line(line) == 0)
      break;

    printf("入力: %s\n", line);
  }
  return 0;
}
