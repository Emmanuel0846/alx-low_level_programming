#include "main.h"

/**
 * append_text_to_file - Entry point to append text at the end of a file.
 * Project by Olaoluwa Emmanuel IDOWU
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int openMe, writeMe, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	openMe = open(filename, O_WRONLY | O_APPEND);
	writeMe = write(openMe, text_content, length);

	if (openMe == -1 || writeMe == -1)
		return (-1);

	close(openMe);

	return (1);
}
