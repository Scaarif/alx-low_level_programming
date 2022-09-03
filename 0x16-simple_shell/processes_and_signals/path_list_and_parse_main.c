#include "main.h"

/**
 * main - create a PATH directories linked list
 * Return: 0 always
 */
int main(void)
{
	char *dirs, *file;
	res _res = {-1, -1}, *res = &_res;
	d_t *head = NULL, *first;

	dirs = _getenv(environ, "PATH", res);
	first = create_path_list(dirs, &head);
	printf("first node: %s\n", first->dir);
	/*printf("\nPRINTING THE LIST: \n\n");*/
	/*print_pathlist(&first);*/
    file ="echo";
    if (parse_path(&head, file))
	{
        printf("%s: found\n", file);
	}
    else
	{
        printf("%s: NOT found\n", file);
	}
	return (0);
}