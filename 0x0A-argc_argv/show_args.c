#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	while (argc--) /*i.e. while argc is +ve starting at argc--*/
		printf("%s\n", *argv++); /*print string, starting at argv[0]*/
	exit(EXIT_SUCCESS);
}

