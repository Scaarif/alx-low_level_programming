#include "main.h"

/**
 * print_path_directories - print PATH directories, one at a time
 * @value: PATH value
 * Return: Nothing
 */
void print_path_directories(char *value)
{
	int i = 0, j = 0;
	char dir[PATH_S];

	if (value)
	{
		for (; value[i] != '\0'; i++)
		{
			/*check for :*/
			if (value[i] != ':')
				dir[j++] = value[i];
			else
			{
				dir[j++] = '\0';
				printf("%s\n", dir);
				j = 0;
			}
		}
		dir[j] = '\0';/*terminate that last directory*/
		printf("%s\n", dir);/*print the last directory*/
	}
}

int main(void)
{
	char *name = "PATH", *value;
	res _res = {-1, -1}, *res;

	res = &_res;
	value = _getenv(environ, name, res);
	print_path_directories(value);
	return (0);
}

				
