#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int num = 0; // 親プロセスと子プロセスで共有されない通常の変数
  pid_t pid = fork();

  if (pid < 0) {
    perror("fork");
    return 1;
  }

  if (pid == 0) {
    // 子プロセス
    printf("子プロセス: PID = %d\n", getpid());
    num = 10; // 子プロセス内で num を変更
    printf("子プロセス: num = %d\n", num);
  }

  // 親プロセス
  printf("親プロセス: PID = %d, 子プロセスのPID = %d\n", getpid(), pid);
  wait(NULL); // 子プロセスの終了を待つ
  printf("親プロセス: num = %d\n", num); // 親プロセスの num の値は変更されない

  return 0;
}
