#include "include/get_next_line.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int fd = open("test", O_RDONLY);
	char *s = get_next_line(fd);
	while (s) {
		printf("%s", s);
		putchar ('\n');
		free (s);
		s = get_next_line(fd);
	}
	free(s);
	return (0);
}
