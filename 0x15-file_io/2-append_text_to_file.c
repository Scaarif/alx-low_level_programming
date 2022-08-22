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
 * append_text_to_file - appends text toa file
 * @filename: name of file to append text to
 * @text_content: characters to write into file
 * Return: 1 on success and -1 otherwise
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int len, fd;

	if (filename)
		fd = open(filename, O_WRONLY | O_APPEND);
	else
		return (-1); /*failed: no filename*/
	if ((int)fd < 0)
		return (-1); /*failed to open file or file doesnt exist*/
	/*else*/
	if (text_content == NULL)
		return (1);/*file exits, dont tamper with*/
	len = str_len(text_content);
	len = write(fd, text_content, len);
	if (len <= 0)
		return (-1); /*failed to write or had no permission to*/
	close(fd);
	return (1);
}

