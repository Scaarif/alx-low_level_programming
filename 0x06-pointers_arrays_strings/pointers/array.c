#include <stdio.h>

int main(void)
{
	int a[5] = {1, 2, 3, 4, 5};
	int i;
	int b[5];

	for (i = 0; i < 5; i++)
	{
		printf("%d", a[i]);
		b[i] = a[i];
	}
	printf("\n");
	printf("&a[4]: %p\n", &a[4]);
	printf("b: %p\n", b);
}

