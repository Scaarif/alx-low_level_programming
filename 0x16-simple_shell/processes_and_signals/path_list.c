#include "main.h"

/**
 * print_pathlist - prints the PATH linked list
 * @head: the list's head
 * Return: Nothing
 */
void print_pathlist(d_t **head)
{
	d_t *curr;

	for (curr = *head; curr != NULL; curr = curr->next)
		printf("%s\n", curr->dir);
}


/**
 * add_node - adds a new node to tail of list
 * @dir: the directory to add as node to list
 * @head: pointer to last list node
 * Return: pointer to head of path list
 */
d_t *add_node(char *dir, d_t **head)
{
	d_t *new_node, *tail;
	
	new_node = malloc(sizeof(d_t));
	if (new_node == NULL)
	{
		unix_error("malloc error");
		return(NULL);
	}
	/*printf("Add dir: %s\n", dir);*/
	new_node->dir = strdup(dir);
	/*printf("added dir: %s\n", new_node->dir);*/
	tail = *head;
	if (tail == NULL)
	{
		new_node->next = tail;
		*head = new_node;/*update head*/
		/*if (*head == NULL)*/
			/*printf("head isn't updating!\n");*/
		/*else*/
			/*printf("updated head dir: %s\n", (*head)->dir);*/
		/*printf("NULL tail\n");*/
	}
	else
	{
		/*printf("tail dir: %s\n", tail->dir);*/
		for (; tail->next != NULL; tail = tail->next)
			;
		new_node->next = NULL;
		tail->next = new_node;/*new tail*/
		/*tail = new_node;*/
	}
	return (*head);
}

/**
 * create_path_list - get next directory and add it to list
 * @dir_str: pointer to remaining directories string
 * @head: pointer to head of list
 * Return: pointer to head(first node)
 */
d_t *create_path_list(char *dir_str, d_t **head)
{
	int i = 0, j = 0;
	char dir[PATH_S];

	for (; dir_str[i] != '\0'; i++)
	{
		if (dir_str[i] != ':')
			dir[j++] = dir_str[i];
		else
		{
			dir[j++] = '\0';
			j = 0;
			/*printf("dir: %s\n", dir);*/
			/*add dir as node to linked list*/
			add_node(dir, head);
			/*printf("test_node dir: %s\n", test->dir);add_node returns the head*/
		}
	}
	dir[j] = '\0';
	/*printf("dir: %s\n", dir);*/
	/*add last node to list*/
	add_node(dir, head);
	/*printf("last added dir: %s\n", dir);*/
	return (*head);
}


