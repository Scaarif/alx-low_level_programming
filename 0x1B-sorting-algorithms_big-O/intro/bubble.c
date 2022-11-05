#include <stdio.h>


int main(void)
{
	int i = 0, j, k, temp, len, sorted = 1, l;
	int arr[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};

	/* sort the array in descending order: largest to smallest */
	len = 10;
	for (; i < len; i++)
	{
		/* compare every two adjacent elements and swap if necessary */
		/**
		 * NOTE: we have to do at least one (outer) pass = (0(n) inner passes)
		 * to determine if a list is already sorted. If no swap happens, the array's already sorted
		 * Else: at the end of an outer(loop) pass, the element at the end of array is sorted
		 * It is therefore excluded from the next pass's (inner) iterations
		 * hence the (len - i) limit/demarcation
		 */
		for (k = 0, j = 1; j < (len - i) && k < (len - 1 - i); j++, k++)
		{
			if (arr[k] > arr[j])
			{
				sorted = 0; /* the array isn't sorted after all */
				temp = arr[k];
				arr[k] = arr[j];
				arr[j] = temp;
				/* print the array after every swap */
			}
		}
		/* check if a swap happened in 'this' pass - if not, array's sorted */
		if (sorted)
			break;
	}
	i = 0;
	while (i < len)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	/* substitute this with print list */
	return (0);
}
