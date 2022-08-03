#include <stdio.h>

int compare(const void *a, const void *b)
{
	int c = *((int*)a);/*void pointers*/
	int d = *((int*)b); /*typecasting and dereferencing*/
	/*returns 1 (true) if equal else 0(false) */
	return (1 ? c == d : 0);
}

int search(void *arr, int arr_size, int ele_size, void *x, int compare(const void *, const void *))
{
	char *ptr = arr; /*first address in array*/
	int i;

	for (i = 0; i < arr_size; i++)
	{
		if (compare(ptr + i * ele_size, x))
			return (i); /*index of x in arr*/
	}
	return (-1); /*if x is not found*/
}

int main(void)
{
	int arr[] = {2, 5, 7, 90, 70};
	int n = sizeof(arr) / sizeof(arr[0]);/*no of elements*/
	int x = 70;
	printf("Returned index is %d\n", search(arr, n, sizeof(int), &x, compare));
	return (0);
}
	
