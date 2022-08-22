#include "main.h"
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * str_len - gets the length of string
 * @str: the str
 * Return: str length
 */

int str_len(char *str)
{
	int len = 0;

	for (; str[len] != '\0'; len++)
		;
	return (len);
}

/**
 * create_file - creates a textfile with given contents
 * @filename: name of file to create
 * @text_content: characters to write into file
 * Return: 1 on success and -1 otherwise
 */
int create_file(const char *filename, char *text_content)
{
	int len, fd;

	if (filename)
		fd = open(filename, O_CREAT | O_RDWR | O_TRUNC,  0600);
	else
		return (-1); /*failed: no filename*/
	if ((int)fd < 0)
		return (-1); /*failed to open file or create file*/
	/*else*/
	if (text_content == NULL)
		len = 0;
	else
		len = str_len(text_content);
	len = write(fd, text_content, len);
	if (len < 0)
		return (-1); /*failed to write*/
	close(fd);
	return (1);
}

