#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - Entry point to read a text file
 * 		and print into POSIX stdout.
 * Project by Olaoluwa Emmanuel IDOWU
 * @filename: A pointer to naming the file.
 * @letters: The amount of letters that the
 *           function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         O/w - the precise number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t openMe, readMe, writeMe;
	char *buff;

	if (filename == NULL)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
		return (0);

	openMe = open(filename, O_RDONLY);
	readMe = read(o, buffer, letters);
	writeMe = write(STDOUT_FILENO, buffer, r);

	if (openMe == -1 || readMe == -1 || writeMe == -1 || writeMe != readMe)
	{
		free(buff);
		return (0);
	}

	free(buff);
	close(openMe);

	return (writeMe);
}
