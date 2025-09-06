#include <stdio.h>
#include <string.h>

#define MAXLINE 1024
#define MAXARGS 64

int read_line(char *line) {
  printf("mysh$ ");

  if (!fgets(line, MAXLINE, stdin))
    return 0;

  line[strcspn(line, "\n")] = '\0';
  return 1;
}

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

int main() {
  char line[MAXLINE];
  char *argv[MAXARGS];

  while (read_line(line)) {
    int argc = parse_line(line, argv);
    printf("コマンド: %s (引数 %d個)\n", argv[0], argc);
  }
  return 0;
}
