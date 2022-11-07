#include <stdio.h>

/**
 * print_sub_arrays - prints the parts of the array currently
 * being worked on
 * @array: the original array
 * @start: the start index
 * @mid: the mid index
 * @end: the end index (inclusive)
 */
void print_sub_arrays(int *array, int start, int mid, int end)
{
	int k, j = mid;

	printf("Merging...\n");
	printf("[left]: ");
	for (k = start; k < mid; k++)
		printf("%d ", array[k]);
	printf("\n");
	printf("[right]: ");
	for (k = j; k < end; k++)
		printf("%d ", array[k]);
	printf("\n");
}

/**
 * copy_merged - copies the merged sub_arrays into the original
 * Also prints the sorted (& merged) sub-array, temp
 * @array: the original
 * @temp: the  sorted array of merged sub-arrays
 * @start: the beginning of first (left) sub-array
 * @index: the last index in temp (inclusive)
 */
void copy_merged(int *array, int *temp, int start, int index)
{
	int k;

	printf("[Done]: ");
	for (k = start; k < index; k++)
	{
		array[k] = temp[k];
		if (k < index - 1)
			printf("%d, ", array[k]);
		else
			printf("%d", array[k]); /* last element */
	}
	printf("\n");
}

// Left source half is A[ iBegin:iMiddle-1].
// Right source half is A[iMiddle:iEnd-1 ].
// Result is B[ iBegin:iEnd-1 ].
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
    int i = iBegin, j = iMiddle, k, h;
    // While there are elements in the left or right runs...
    print_sub_arrays(A, iBegin, iMiddle, iEnd);
    for (k = iBegin; k < iEnd; k++) {
    // If left run head exists and is <= existing right run head.
        if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;
        }
    }
    /* print sorted & merged sub_array (B)*/
    printf("[Done]: ");
	for (h = iBegin; h < k; h++)
	{
		if (h < k - 1)
			printf("%d, ", A[h]);
		else
			printf("%d", A[h]); /* last element */
	}
	printf("\n");
    

}
void CopyArray(int A[], int iBegin, int iEnd, int B[])
{
    int k;

    for (k = iBegin; k < iEnd; k++)
    B[k] = A[k];
}

// Split A[] into 2 runs, sort both runs into B[], merge both runs from B[] to A[]
// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
    int iMiddle;
    
    if (iEnd - iBegin <= 1) // if run size == 1
    return; // consider it sorted
    // split the run longer than 1 item into halves
    iMiddle = (iEnd + iBegin) / 2; // iMiddle = mid point
    // recursively sort both runs from array A[] into B[]
    TopDownSplitMerge(A, iBegin, iMiddle, B); // sort the left run
    TopDownSplitMerge(A, iMiddle, iEnd, B); // sort the right run
    // merge the resulting runs from array B[] into A[]
    TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

// Array A[] has the items to sort; array B[] is a work array.
void TopDownMergeSort(int A[], int B[], int n)
{
    CopyArray(A, 0, n, B); // one time copy of A[] to B[]
    TopDownSplitMerge(B, 0, n, A); // sort data from B[] into A[]
}

void main()
{
    int i, arr[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    int arr2[10];
    size_t n;
    
    n = sizeof(arr) / sizeof(arr[0]);
    TopDownMergeSort(arr, arr2, n);
    printf("\n The sorted array is: \n");
    for(i=0;i<n;i++)
        printf(" %d\t", arr[i]);
}