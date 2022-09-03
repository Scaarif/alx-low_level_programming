#include "main.h"

/**
 * main - reading directory contents example
 * int ac: no args
 * @av: string array of args
 * Return: 0 always
 */

int main(int ac, char **av)
{
	DIR *d_stream;
	struct dirent *d_entry;

	if (ac < 2)
	{
		printf("Usage: %s <foldername>\n", av[0]);
		return (1);
	}
	d_stream = opendir(av[1]);/*returns the DIR, a list of entries in the folder*/
	if (d_stream)/*if OK, otherwise opendir returns NULL*/
	{
		errno = 0;/*track to differentiate an error from an end of stream condition*/
		while ((d_entry = readdir(d_stream)) != NULL)
			printf("Found file: %s\n", d_entry->d_name);
		/*a change in value of errno indicates a readdir error*/
		if (errno != 0)/*value changed, actual error (not end of stream) occurred*/
			unix_error("readdir error");
		closedir(d_stream);/*close stream and free resources*/
	}
	else
		unix_error("opendir error");
	exit(0);
}

