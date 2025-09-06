# Step 0: プロンプトの表示

このステップでは、シェルの基本機能であるプロンプト表示を実装します。  
ユーザーに対話的にコマンドを入力してもらうためのプロンプトを作成しましょう。

## 学ぶこと

- Cプログラムの基本構造 (`#include`, `main`, `return 0`)
- 標準出力への表示 (`printf`)
- コンパイル・実行の流れ

## やってみましょう

1. [practice.c](./practice.c)の TODO に従ってコードを埋めてみましょう。

2. コンパイル・実行してみましょう。
```shell
cd step0_prompt/
gcc practice.c -o practice
./practice
```

3. プロンプトが表示されたことを確認しましょう。

出力例
```shell
$ ./practice
mysh$
$
```