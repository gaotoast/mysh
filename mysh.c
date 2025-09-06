#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAXLINE 1024 // 1行の最大文字数
#define MAXARGS 64   // コマンドの最大引数数

/**
 * コマンドライン入力を受け取る関数
 * @param line 入力を格納するバッファ
 * @return 成功時1、EOF時0
 */
int	read_line(char *line) {
  // プロンプトを表示
	printf("mysh$ ");

  // 標準入力から1行読み込み
	if (fgets(line, MAXLINE, stdin) == NULL)
		return (0); // EOFの場合は0を返す

  // 改行文字を終端文字に変更
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
	int argc = 0;                    // 引数カウンタ
	char *token = strtok(line, " "); // スペースで区切る
	
  // トークンを引数配列に格納
	while (token != NULL && argc < MAXARGS - 1) {
		argv[argc] = token;
		argc++;
		token = strtok(NULL, " "); // 次のトークンを取得
	}

	argv[argc] = NULL; // 配列の終端をNULLにする（execvpの要件）
	return (argc);
}

/**
 * コマンドを実行する関数
 * @param argv コマンドと引数の配列
 */
void	execute(char *argv[]) {
  // コマンドが空の場合は何もしない
	if (argv[0] == NULL)
		return ;

  // 子プロセスを作成
	pid_t pid = fork();
	if (pid < 0) {
		perror("fork");
		return ;
	}

  // 子プロセスの場合
	if (pid == 0) {          
		execvp(argv[0], argv); // コマンドを実行
		perror("exec");
		exit(1); // 子プロセスを終了
	}

	// 親プロセスは子プロセスの終了を待つ
	wait(NULL);
}

/**
 * メイン関数 - シェルの主要ループ
 */
int	main() {
	char line[MAXLINE];  // コマンドライン入力用バッファ
	char *argv[MAXARGS]; // コマンド引数配列
	
  // シェルのメインループ
	while (1) {
    // コマンドライン読み取り（EOFで終了）
		if (read_line(line) == 0)
			break;

    // コマンドライン解析
		int argc = parse_line(line, argv);

    // コマンドがあれば実行
		if (argc > 0)
			execute(argv);
	}
	return (0);
}
