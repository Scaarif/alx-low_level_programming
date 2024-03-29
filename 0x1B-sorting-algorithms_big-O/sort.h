#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

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

/* Provided functions */
void print_array(const int *array, size_t size);
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

#endif /* SORT_H */
