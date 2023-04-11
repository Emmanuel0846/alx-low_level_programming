#include "main.h"

/**
 * create_file - Entry point to create a file.
 * Project by oLAOLUWA eMMANUEL idowu
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int openMe, writeMe, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	openMe = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	writeMe = write(openMe, text_content, length);

	if (openMe == -1 || writeMe == -1)
		return (-1);

	close(openMe);

	return (1);
}
