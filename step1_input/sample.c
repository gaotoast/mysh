#include <stdio.h>
#include <string.h>

#define MAXLINE 1024

int read_line(char *line) {
  printf("mysh$ ");

  if (!fgets(line, MAXLINE, stdin))
    return 0;

  line[strcspn(line, "\n")] = '\0';
  return 1;
}

int main() {
  char line[MAXLINE];

  while (1) {
    if (!read_line(line))
      break;

    printf("入力: %s\n", line);
  }
  return 0;
}
