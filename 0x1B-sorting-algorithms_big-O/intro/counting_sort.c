#include "sort.h"

/**
 * _memcpy - copies information between void pointers.
 * @newptr: destination pointer.
 * @ptr: source pointer.
 * @size: size of the new pointer.
 * Return: Nothing
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	int *int_ptr = (int *)ptr;
	int *int_newptr = (int *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		int_newptr[i] = int_ptr[i];
}

/**
 * get_range - returns the upperbound of integers in an array
 * @array: the array from which to get range
 * @size: the number of elements in the array
 * Return: the upperbound
 */
int get_range(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max + 1);
}

/**
 * actual_counting_sort - sorts an array in ascending order using
 * the (non-comparative) linear algorithm, Couting Sort
 * Description: uses 3 arrays, an input, output & temporary storage
 * array. The temporary storage array (of size:
 * k = max integer in array + 1) holds first, the count of each integer
 * in input array (how many times it appears) and is updated, in place
 * to hold the position(ing) of said integers.
 * temporary_array[i] holds [i] + [i - 1] i.e. all the count of all the
 * elemnts up to that position.
 * @array: the array to sort
 * @n: size of the array
 * @B: array to hold the values in the process
 * @K: the range of integers in the array to sort
 */
void actual_counting_sort(int array[], int n, int B[], int K)
{
	int *C, i, j;

	/* dynamically allocate memory to temp array */
	C = malloc(sizeof(int) * K);
	if (C == NULL)
		return; /* malloc failed */
	/* complexity == O(K) */
	for (i = 0; i < K; i++)
		C[i] = 0; /* initialize the temp array of size K */
	/* complexity == O(n) */
	for (j = 0; j < n; j++)
	{
		/* array[j] == int element @ [j], increment its count */
		C[array[j]] = C[array[j]] + 1;
	}
	/* C[i] now contains the number of elements equal to i */
	/* complexity == O[K] */
	for (i = 1; i < K; i++)
	{
		/* current + all prev elements: gives position of I elem */
		C[i] = C[i] + C[i - 1];
	}
	/* C[i] now contains the number of elements <= i */
	display(C, K);
	/* complexity == O(n) */
	for (j = n - 1; j >= 0; j--)
	{
		/*sub 1 since positioning starts @ 1 (not 0), its based on count */
		C[array[j]] = C[array[j]] - 1;
		B[C[array[j]]] = array[j];
	}
	/* B[] now contains the sorted elements of array[] */
	free(C); /* free temp array - no longer needed */
}

/**
 * counting_sort - sorts elements of an array using the linear algorithm,
 * Counting Sort (which's also a stable sorting algorithm)
 * @array: the array to sort
 * @size: the number of elements in the array
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int k, *output;

	/* get k == max element in array + 1*/
	k = get_range(array, size);
	/* dynamically allocate memory (size k) to output array */
	output = malloc(sizeof(int) * k); /* will hold the sorted values */
	/* check that malloc didn't fail */
	if (output == NULL)
		return; /* malloc failed */
	/* call actual_counting_sort */
	actual_counting_sort(array, size, output, k);
	/* copy output into array */
	_memcpy(array, output, size);
	free(output); /* frees the dynamically allocated space */
}
