#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char *s;

	if (argc > 1)
	{
		s = argv[1];
		printf("%s\n", s);
		if (*s < '0' || *s > '9')
			{
				printf("Error\n");
				return (1);
			}
		printf("%d\n", atoi(argv[1]));
	}
	return (0);
}

