#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *createBuffer(char *myFile);
void closeFile(int fileDesc);

/**
 * createBuffer -Entry point to allocate 1024 bytes for a buffer.
 * pROJECT BY Olaoluwa Emmanuel IDOWU
 * @myFile: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *createBuffer(char *myFile)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", myFile);
		exit(99);
	}

	return (buff);
}

/**
 * closeFile -Entry point to close file descriptors.
 * @fileDesc: The file descriptor to be closed.
 */
void closeFile(int fileDesc)
{
	int closeMe;

	closeMe = close(fileDesc);

	if (closeMe == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fileDesc %d\n", fileDesc);
		exit(100);
	}
}

/**
 * main - Entry point to  Copy the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, readMe, writeMe;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = createBuffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	readMe = read(from, buff, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || readMe == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		writeMe = write(to, buff, readMe);
		if (to == -1 || writeMe == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		readMe = read(from, buff, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (readMe > 0);

	free(buff);
	closeFile(from);
	closeFile(to);

	return (0);
}
