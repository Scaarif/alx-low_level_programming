/**
 * C program to detect a loop in a linked list
 * Description: such a list has no end; doesn't point to NULL
 */

#include <stdlib.h>
#include <stdio.h>

/**
 * struct Node - linked list node
 * @n: int data
 * @next: next node in list
 */
typedef struct Node
{
	int n;
	struct Node *next;
} node;

/**
 * push - adds a node to the begining of the list
 * @head_ref: head of list
 * @n: new node's int data
 * Return: nothing
 */
void push(node **head_ref, int n)
{
	node *new_node = malloc(sizeof(node));

	/*check that new_node suceeds*/
	if (new_node == NULL)
		printf("new_node fialied\n");
	new_node->n = n;
	new_node->next = *head_ref;
	/*update head to new_node*/
	*head_ref = new_node;
}

/**
 * detectLoop - detects presence of a loop in a list
 * @list: the list to check
 * Return: 1 if loop and 0 otherwise
 */
int detectLoop(node *list)
{
	node *S = list, *F = list;

	while (S && F && F->next) /*as long as none of these are NULL*/
	{
		S = S->next;/*move forward a node*/
		F = F->next->next;/*move forward 2 nodes*/
		if (S == F)
			return (1);/*if true*/
	}
	return (0);/*if false*/
}

/**
 * loopNode - returns loopNode in a list
 * @list: the list to check
 * Return: 1 if loop and 0 otherwise
 */
node *loopNode(node *list)
{
	node *S = list, *F = list;

	while (S && F && F->next) /*as long as none of these are NULL*/
	{
		S = S->next;/*move forward a node*/
		F = F->next->next;/*move forward 2 nodes*/
		if (S == F)
			break;
	}
	/*return S to head of list*/
	S = list;
	while (S && F && F->next)
	{
		S = S->next;
		F = F->next;
		if (S == F)
		{
			/*printf("S: %d\n", S->n);*/
			/*printf("F: %d\n", F->n);*/
			break;
		}
	}
	return (S);/*meeting node == loopNode*/
}


/**
 * main - check code
 * Return: always 0
 */
int main(void)
{
	node *head = NULL;
	node *the_node;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);
	/*create a testing loop*/
	head->next->next->next->next = head;
	if (detectLoop(head))
	{
		printf("Loop found!\n");
		the_node = loopNode(head);
		printf("loopNode: %d\n", the_node->n);
	}
	else
		printf("No loop\n");
	return (0);
}

