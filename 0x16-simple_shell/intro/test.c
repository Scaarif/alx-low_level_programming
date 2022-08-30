#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - prints all args without using ac
 *
 * Return: 0
 */

int main(__attribute__((unused))int ac, char **av)
{
        int i;
        i = 1;
        char *(*ptr) = malloc(sizeof(av));

        if(ptr == NULL)
                exit(1);

        ptr = av;

        if (ptr[1] == NULL)
        {
                printf("No arg passed\n");
                exit(1);
        }
        while (strcmp(ptr[i],"\\0") != 0)
        {
                printf(" ptr[%d] : %s \n",*(ptr[i]), ptr[i]);
                i++;
        }
        putchar('\n');
        return (0);
}
