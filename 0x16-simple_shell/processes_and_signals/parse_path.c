#include "main.h"

/**
 * parse_path - searches for the executable in PATH
 * @head: the head_node to the path dirs_list to parse one after the other
 * @file: the file to look for in path
 * Return: 1 if found and 0 otherwise
 */
int parse_path(d_t **head, char *file)
{
	d_t *curr = *head;/*current node*/
	DIR *d_stream;
	struct dirent *d_entry;

	/*for directories in list, get current directory*/
	for (; curr != NULL; curr = curr->next)
	{
		/*get a list of entries in the current directory*/
		d_stream = opendir(curr->dir);
		if (d_stream)
		{
			errno = 0;/*track to differentiate an error from end of stream*/
			while ((d_entry = readdir(d_stream)) != NULL)
			{/*get next entry/file in current_directory & compare with file*/
				if (strcmp(d_entry->d_name, file) == 0)
					return (1);/*return file in path*/
			}
			if (errno != 0)
				unix_error("readdir error");
			closedir(d_stream);
		}
		else
			unix_error("opendir error");
	}
	return (0);/*file not in path*/
}
