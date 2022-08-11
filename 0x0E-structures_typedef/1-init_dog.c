#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - initializes the structure dog
 * @d: pointer to dog structure
 * @name: dog name
 * @age: dog age
 * @owner: dog owner
 * Return: nothing
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name; /*same as: (*d).name = name */
		d->age = age;
		d->owner = owner;
	}
}

