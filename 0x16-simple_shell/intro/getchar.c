#include <stdio.h>

int main(void)
{
	int c;

	/**
	 * c = getchar();
	 * while (c != EOF)
	 * {
	 * putchar(c);
	 * c = getchar();
	 * }
	 * return (0);
	 * }
	 *
	 */
	while ((c = getchar()) != EOF)
		putchar(c);
	return (0);
}
