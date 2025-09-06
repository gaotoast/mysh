#include <stdio.h>
#include <unistd.h>

int	main() {
	char	*args[] = {"ls", "-l", NULL};

	printf("execvp を使って ls -l を実行します\n");
	if (execvp("ls", args) == -1) {
		perror("execvp");
		return (1);
	}
	return (0);
}
