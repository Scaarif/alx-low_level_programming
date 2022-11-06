#include "sort.h"

/**
 * swap - swaps two elements of an array
 * @array: the array
 * @pos1: the first index (element to swap)
 * @pos2: the second index (element to swap)
 * Return: Nothing
 */
void swap(int *array, int pos1, int pos2)
{
	int temp;

	/* dont swap the same element */
	if (pos1 == pos2)
		return;
	temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;
}

/**
 * display - prints out the array
 * @array: the array to print out
 * @size: the array to print out
 * Return: Nothing
 */
void display(int *array, size_t size)
{
	int i = 0;

	printf("[");
	for (; i < (int)size; i++)
		printf("%d ", array[i]);
	printf("]\n");
}

/**
 * print_list - prints a list of integers
 * @list: the list to be printed
 * Return: Nothing
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		i++;
		list = list->next;
	}
	printf("\n");
}
