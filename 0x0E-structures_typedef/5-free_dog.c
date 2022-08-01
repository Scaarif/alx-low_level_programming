#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees Dog
 * @d: pointer to Dog
 * Return: Nothing
 */
void free_dog(dog_t *d)
{
		free(d);
}

