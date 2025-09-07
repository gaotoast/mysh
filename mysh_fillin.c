// 上級者向け mysh.c 穴埋め練習ファイル
// 各空欄（____）を適切なコードで埋めてください。

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
	____;

	// 標準入力から1行読み込み
	if (____)
		return (0); // EOFの場合は0を返す

	// 改行文字を終端文字に変更
	____;
	return (1);
}

/**
 * コマンドライン文字列を解析して引数配列に分割する関数
 * @param line 解析する文字列
 * @param argv 引数を格納する配列
 * @return 引数の数
 */
int	parse_line(char *line, char *argv[]) {
	int argc = 0;       // 引数カウンタ
	char *token = ____; // スペースで区切る

  // トークンを引数配列に格納
	while (____) {
		argv[argc] = token;
		argc++;
		token = ____; // 次のトークンを取得
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
	if (____)
		return ;

	// 子プロセスを作成
	pid_t pid = ____;
	if (pid < 0) {
		perror("fork");
		return ;
	}

	// 子プロセスの場合
	if (____) {
		____; // コマンドを実行
		perror("exec");
		exit(1); // 子プロセスを終了
	}

	// 親プロセスは子プロセスの終了を待つ
	____;
}

/**
 * メイン関数 - シェルの主要ループ
 */
int	main() {
	char line[MAXLINE];  // コマンドライン入力用バッファ
	char *argv[MAXARGS]; // コマンド引数配列

	// シェルのメインループ
	while (1) {
		if (____)
			break ;
		
    // コマンドライン解析
		int argc = ____;
		
    // コマンドがあれば実行
		if (____)
			____;
	}
	return (0);
}
