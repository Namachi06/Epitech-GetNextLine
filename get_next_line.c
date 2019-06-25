/*
** EPITECH PROJECT, 2017
** get_next_line
** File description:
** 	Automaticly read one line of a text file;
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char *my_realloc(char *string, int length) {
	char *new_memory;

	new_memory = (char *)malloc(sizeof(char) * length + 1);
	if (string == NULL) {
		return (new_memory);
	}
	for (int i = 0; string[i] != '\0'; i++) {
		new_memory[i] = string[i];
	}
	free(string);
	return (new_memory);
}

char read_next_char(int fd) {
	int static r;
	int static buffer_index = 0;
	int static read_once = 0;
	char static buffer[READ_SIZE];

	if (READ_SIZE == buffer_index || read_once == 0) {
		r = read(fd, buffer, sizeof(buffer));
		read_once = 1;
		buffer_index = 0;
	}
	if (r == 0) {
		return (-1);
	}
	buffer_index++;
	return (buffer[buffer_index - 1]);
}

char *get_next_line(int fd)
{
	int nb_char = 0;
	int block = 1;
	char *word;
	char c;

	if (fd < 0)
		return (NULL);
	if ((word = (char *)malloc(sizeof(char) * READ_SIZE)) == NULL)
		return (NULL);
	do {
		c = read_next_char(fd);
		if ((c != -1) && (c != '\n')) {
			if (nb_char >= (READ_SIZE * block)) {
				block++;
				word = my_realloc(word, block * READ_SIZE);
			}
			word[nb_char] = c;
			nb_char++;
		}
	} while ((c != -1) && (c != '\n'));
	if (c == -1)
		return (NULL);
	word[nb_char] = '\0';
	return (word);
}
