#include <stdio.h>


int main(void)
{
	int i = 0, j, k, temp, len;
	int arr[] = {30, 52, 29, 87, 63, 27, 19, 54};

	/* sort the array in descending order: largest to smallest */
	len = 8;
	for (; i < len; i++)
	{
		/* compare every two adjacent elements and swap if necessary */
		for (k = 0, j = 1; j < len && k < (len - 1); j++, k++)
		{
			if (arr[k] < arr[j])
			{
				temp = arr[k];
				arr[k] = arr[j];
				arr[j] = temp;
			}
		}
	}
	i = 0;
	while (i < len)
	{
		printf("%d,", arr[i]);
		i++;
	}
	printf("\n");
	return (0);
}
