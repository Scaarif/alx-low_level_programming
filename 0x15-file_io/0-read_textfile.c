#include "main.h"
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/**
 * read_textfile - reads a textfie and prints it to POSIX
 * std output
 * @filename: name of file to read from
 * @letters: no of characters to read and write
 * Return: no of characters written if success and 0 otherwise
 */
size_t read_textfile(const char *filename, size_t letters)
{
	size_t len, fd;
	char *buffer;

	if (filename)
		fd = open(filename, O_RDONLY, 0);
	else
		return (0); /*failed: no file*/
	if ((int)fd < 0)
		return (0); /*failed to open file*/
	/*else*/
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0); /*buffer failed*/
	len = read(fd, buffer, letters);
	if ((int)len < 0)
		return (0); /*failed to read*/
	len = write(1, buffer, len);
	if ((int)len < 0)
		return (0); /*failed to write*/
	close(fd);
	return (len);
}

