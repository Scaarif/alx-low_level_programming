#include <stdio.h>
#include <stdlib.h>

#define MAXLEVEL 5

typedef struct ListNode {
	int data;
	struct ListNode *next[1];
} node_t;

typedef struct SkipList {
	node_t *header;
	int listLevel; /* current level of list */
} list_t;

list_t list;

/* SkipList Initialization */
void initList()
{
	int i;

	if ((list.header = malloc(sizeof(node_t) + MAXLEVEL * sizeof(node_t *))) == 0)
	{
		printf(" Malloc error\n");
		exit(1);
	} 
	/* else, memory successfully allocated */
	for (i = 0; i <= MAXLEVEL; i++)
		list.header->next[i] = list.header; /* make it point to itself? */
	list.listLevel = 0;
	printf("list initialized!\n");
}

/* Insertion Algorithm */
node_t *insertElement(int data)
{
	int i, newLevel;
	node_t *update[MAXLEVEL + 1]; /* an array of (max_level + 1) nodes */
	node_t *temp;

	temp = list.header;
	/* find the location to insert the element, starting from the top most list */
	for (i = list.listLevel; i >= 0; i--)
	{
		printf("in loop -> traversing levels\n");
		/* traverse each list (level) accordingly */
		while (temp->next[i] != list.header && temp->next[i]->data < data)
		{
			printf("temp->%d & temp->next[%d]->%d\n", temp->data, i, temp->next[i]->data);
			temp = temp->next[i]; /* advance forward in the level */
		}
		printf("exiting level %d\n", i);
		update[i] = temp; /* update/append the array of nodes with last node to traverse at each level */
	}
	printf("exited loop\n");
	temp = temp->next[0]; /* this should be the value we are looking for */
	printf("at position to insert\n");
	if (temp != list.header && temp->data == data)
	{
		printf("Node (%d) not inserted (already exists)\n", data);
		return (temp); /* why are we returning? This'd be a search for the value, right? UNLESS WE DONT WANT DUPLICATES!!! */
	}
	printf("past looking at position to insert\n");
	/* else determine level */
	for (newLevel = 0; rand() < RAND_MAX / 2 && newLevel < MAXLEVEL; newLevel++); /* proverbial coin toss for heads*/
	/* update levels (add new ones) if newLevel > current listLevel (within MAXLEVEL offcourse) */
	if (newLevel > list.listLevel)
	{
		for (i = list.listLevel + 1; i <= newLevel; i++)
			update[i] = list.header;
		list.listLevel = newLevel;
	}
	/* create the new node (with date as value) */
	if ((temp = malloc(sizeof(node_t) + newLevel * sizeof(node_t *))) == 0)
	{
		printf("insfficient memory (insertElement)\n");
		exit(1); /* malloc failure */
	} /* else */
	temp->data = data;
	for (i = 0; i < newLevel; i++)
	{
		/* update next links on all levels */
		update[i]->next[i] = temp; /* remember update[i] == nodes just smaller than this node */
	}
	printf("Node (%d) inserted\n", data);
	return (temp);
}

/* Deletion Algorithm */
void deleteElement(int data)
{
	int i;
	node_t *update[MAXLEVEL + 1], *temp;

	temp = list.header;
	/* find the node containing data, to delete it - again, start at the very top lane/list */
	for (i = list.listLevel; i >= 0; i--)
	{
		/* traverse a level */
		while (temp->next[i] != list.header && temp->next[i]->data < data)
			temp = temp->next[i];
		update[i] = temp; /* the node just smaller than target node */
	}
	temp = temp->next[0]; /* this should be the target node */
	if (temp == list.header || !(temp->data == data))
		return; /* target node not present */
	/* else, adjust next pointers (to target's next) on all levels */
	for (i = 0; i <= list.listLevel; i++)
	{
		if (update[i]->next[i] != temp)
			break; /* we're past the target's top most level */
		update[i]->next[i] = temp->next[i]; /* else target's prev node at each level should point to target's next */
	}
	free(temp);
	/* adjust header level (only if all nodes at a level have been deleted I think ) */
	while ((list.listLevel > 0) && (list.header->next[list.listLevel] == list.header))
		list.listLevel--;
}

/* Search/find Algorithm */
node_t *findElement(int data)
{
	int i;
	node_t *temp = list.header;

	for (i = list.listLevel; i >= 0; i--)
	{
		/* traverse a level/lane  */
		while (temp->next[i] != list.header && temp->next[i]->data < data)
			temp = temp->next[i];
	}
	temp = temp->next[0]; /* should be the target node, else the target doesnt exist */
	if (temp != list.header && temp->data == data)
		return (temp); /* found! */
	return (0); /* doesn't exist otherwise */
}

/* helper function */
void print_array(int *array, int start, int stop)
{
	printf("Array: [");
	for (; start < stop; start++)
		printf("%d, ", array[start]);
	printf("%d]\n", array[stop]);
}

/* MAIN - test the algos */
int main(int argc, char **argv)
{
	int i, *a, maxnum = atoi(argv[1]);

	initList();
	if ((a = malloc(maxnum * sizeof(*a))) == 0)
	{
		fprintf(stderr, "malloc error (a)\n");
		exit(1);
	}
	for (i = 0; i < maxnum; i++)
		a[i] = rand() / 1000000;

	printf("Random, %d items\n", maxnum);
	print_array(a, 0, maxnum - 1);
	for (i = 0; i < maxnum; i++)
	{
		printf("inserting array[%d] -> %d\n", i, a[i]);
		insertElement(a[i]);
	}
	for (i = maxnum - 1; i >= 0; i--)
	       findElement(a[i]);
	for (i = maxnum - 1; i >= 0; i--)
		deleteElement(a[i]);
	return (0);
}
