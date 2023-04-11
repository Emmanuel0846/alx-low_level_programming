#ifndef MAIN_H
#define MAIN_H

/*
 * Desc: Header file containing prototypes for all functions
 *		written in the 0x14-file_io directory.
 * By Olaoluwa Emmanuel
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int _putchar(char c);

/*
 * Write a function that reads a text file and prints it to the
 *		POSIX standard output.
 */
ssize_t read_textfile(const char *filename, size_t letters);

/*
 * A prototype that Create a function that creates a file.
 */
int create_file(const char *filename, char *text_content);

/*
 * A prototype that Write a function that appends text at the end of a file.
 */
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */
