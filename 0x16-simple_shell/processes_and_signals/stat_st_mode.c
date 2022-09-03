#include "main.h"

/**
 * main - stat's st_mode in action
 * Return: 0 always
 */
int main(int ac, char **av)
{
	struct stat status;
	char *type, *readok;

	if (ac < 2)
	{
		printf("Usage: %s <filename>\n", av[0]);
		return (1);
	}
	if (stat(av[1], &status) == 0)/*OK*/
	{
		if (S_ISREG(status.st_mode)) /*Determine file type*/
			type = "regular file";
		else if (S_ISDIR(status.st_mode))
			type = "directory";
		else
			type = "other";
		if (status.st_mode & S_IRUSR)/*check read access*/
			readok = "yes";
		else
			readok = "no";
	}
	else
	{
		unix_error("stat error");
	}
	printf("type: %s, read: %s of size %ld bytes\n", type, readok, status.st_size);
	return (0);
}


