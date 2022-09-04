#include "main.h"

char *_get_file(char *pathname)
{
	int i = 0, j = -1;
	char *file;

	for (;pathname[i] != '\0'; i++)
	{
		if (pathname[i] == '/')
			j = i;/*get pos of last / in pathname*/
	}
	if (j > -1)
	{
		file = pathname;
		printf("%s\n", file);
		for (j++, i = 0; (pathname[i] = file[j]) != '\0'; j++, i++)
			;
		pathname[j] = '\0';/*terminate name*/
		printf("%s\n", pathname);
	}
	/*else, there's no / - so filename provided*/
	return (pathname);
}

/**
 * main - create a PATH directories linked list
 * Return: 0 always
 */
int main(void)
{
	char *dirs, *file,  _file[] ="/usr/bin/echo";
	res _res = {-1, -1}, *res = &_res;
	d_t *head = NULL, *first;

	dirs = _getenv(environ, "PATH", res);
	first = create_path_list(dirs, &head);
	printf("first node: %s\n", first->dir);
	/*printf("\nPRINTING THE LIST: \n\n");*/
	/*print_pathlist(&first);*/
	printf("_file: %s\n", _file);
	file = _get_file(_file);
	printf("_file after: %s\n", _file);
    if (parse_path(&head, _file))
	{
        printf("%s: found\n", file);
	}
    else
	{
        printf("%s: NOT found\n", file);
	}
	return (0);
}