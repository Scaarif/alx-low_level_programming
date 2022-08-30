#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*ssize_t getline(char **lineptr, size_t *n, FILE *stream);*/
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    
    /*getline returns no of chars read and -1 on failure*/
    printf("Type a command: ");
    nread = getline(&line, &len, stdin);/*reading from stdin*/
    printf("%zu characters were read.\n", nread);
    printf("You typed: '%s'\n", line);
    exit(EXIT_SUCCESS);
}