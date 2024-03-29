#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structures */

/**
 * struct listint_s - Doubly linked list node
 * @n: integer stored in the node
 * @prev: pointer to the previous element of the list
 * @next: pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * struct heap - a heap structure
 * @array: the array to represent the heap
 * @count: the number of elements (nodes) in heap
 * @capacity: the size (no of elements it can hold) of the heap
 */
typedef struct heap
{
	int *array;
	int count;
	int capacity;
} heap_t;

/* Provided functions */
void print_array(const int *array, size_t size);
void display(int *array, size_t size);
void print_list(const listint_t *list);

/* helper functions */
int lomuto_partition(int *array, int lowerbound, int upperbound, size_t size);
int hoare_partition(int *array, int lowerbound, int upperbound, size_t size);
void swap(int *array, int pos1, int pos2);

/* Implementation functions */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *arr, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void cocktail_sort(int *array, size_t size);
void counting_sort(int array[], size_t size);
void radix_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);

#endif /* SORT_H */
