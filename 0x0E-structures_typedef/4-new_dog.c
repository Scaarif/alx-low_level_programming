#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog
 * @name: dog name
 * @age: dog age
 * @owner: dog owner
 * Return: pointer to new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *newDog;
	int i, j, k;
	char *m, *n;

	newDog = malloc(sizeof(dog_t));
	if (newDog == NULL)
		return (NULL);
	for (i = 0; name[i] != '\0'; i++)
	for (j = 0; owner[j] != '\0'; j++)

	m = malloc(sizeof(char) * i + 1);
	if (m == NULL)
	{
		free(newDog);
		return (NULL);
	}
	n = malloc(sizeof(char) * j + 1);
	if (n == NULL)
	{
		free(n);
		free(newDog);
		return (NULL);
	}
	for (k = 0; k <= i; k++)
		m[k] = name[k];
	for (k = 0; k <= j; k++)
		n[k] = owner[j];
	newDog->name = name;
	newDog->age = age;
	newDog->owner = owner;
	return (newDog);
}

