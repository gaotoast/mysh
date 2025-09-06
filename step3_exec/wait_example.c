#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  pid_t pid = fork();

  if (pid < 0) {
    perror("fork");
    return 1;
  }

  if (pid == 0) {
    // 子プロセス
    printf("子プロセス: 実行中\n");
    sleep(3); // 子プロセスが3秒間実行される
    printf("子プロセス: 終了\n");
  }

  // 親プロセス
  printf("親プロセス: 子プロセスの終了を待っています\n");
  wait(NULL); // 子プロセスの終了を待つ
  printf("親プロセス: 子プロセスが終了しました\n");

  return 0;
}
