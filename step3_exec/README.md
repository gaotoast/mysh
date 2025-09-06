# Step 3: コマンド実行

シェルの核心機能である外部コマンドの実行を実装します。
`fork`と`exec`の仕組みを使って、入力されたコマンドを実行します。

## 学ぶこと

- プロセスの作成 (`fork`)
- 外部コマンドの実行 (`execvp`)
- 親子プロセスの連携と待機 (`wait`)

## やってみましょう

1. [practice.c](./practice.c) の TODO に従ってコードを埋めてみましょう。

2. コンパイル・実行してみましょう。

```shell
cd step3_exec/
gcc practice.c -o practice
./practice
```

3. 動作確認：
   - 様々なコマンドを実行してみましょう（例: `ls -la`, `pwd`, `echo hello world`）
   - シェルがコマンド終了後も続けて動作することを確認します
   - 存在しないコマンドを入力した場合のエラー処理も確認します

## 補足

以下のファイルを参考にして、`fork`、`execvp`、`wait` の動作を体験してみましょう。

1. [fork_example.c](./fork_example.c): プロセスの分岐を体験
2. [execvp_example.c](./execvp_example.c): 外部コマンドを実行
3. [wait_example.c](./wait_example.c): 子プロセスの終了を待機

これらのファイルをコンパイルして実行することで、各機能の動作を確認できます。

```shell
# 例: fork_example.c のコンパイルと実行
cd step3_exec/
gcc fork_example.c -o fork_example
./fork_example
```
