#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
 * main - copies contents from one file to another
 * Description: truncates the to_file if it already exists
 * @argc: args count
 * @argv: args strings array
 * Return: exists with status code 97 if argc != 3 and 98 or 99
 * if an input output proccess fails
 */

int main(int argc, char **argv)
{
	int f_from, f_to, done;
	long _read = 0, len = 1024, more = 0, i;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(2, "Usage:cp file_from file_to\n"), exit(97);
	}
	f_from = open(argv[1], O_RDONLY);
	f_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (f_from < 0)
		exit(98);
	_read = read(f_from, buffer, len);
	if (_read < 0)
		dprintf(2, "Can't read from %s\n", argv[1]), exit(98);
	if (f_to < 0)
		exit(99);
	done = write(f_to, buffer, _read);
	if (done < 0)
		dprintf(2, "Can't write to %s\n", argv[2]), exit(99);
	close(f_to);
	f_to = open(argv[2], O_WRONLY | O_APPEND);/*to append*/
	if (_read == len)/*actually read 1024 chars, there myt be more*/
		for (i = 1; lseek(f_from, _read, 0) >= 0 &&
				_read == len * i; _read += more, i++)
		{
			more = read(f_from, buffer, len);
			if (more < 0)
			{
				dprintf(2, "Can't read from %s\n", argv[1]), exit(98);
			}
			done = write(f_to, buffer, more);/*append what's read*/
			if (done < 0)
			{
				dprintf(2, "Can't write to %s\n", argv[2]), exit(99);
			}
		}
	close(f_from), close(f_to);
	return (0);
}

