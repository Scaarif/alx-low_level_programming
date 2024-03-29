#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    if (argc != 2)
    {
        /*fprintf(stderr, "Usage: %s <file>\n", argv[0]);*/
        /*exit(EXIT_FAILURE);*/
        stream = stdin;
    }
    else
        stream = fopen(argv[1], "r");
    if (stream == NULL)
    {
        perror("fopen error");
        exit(EXIT_FAILURE);
    }
    /*ssize_t getline(chra **lineptr, size_t *n, FILE *stream);*/
    while ((nread = getline(&line, &len, stream)) != -1)
    {
        printf("Retrieved line of length %zu:\n", nread);
        fwrite(line, nread, 1, stdout);/*write to stdout, i item of nread size from line*/
    }
    /*getline returns no of chars read and -1 on failure*/
    free(line);
    fclose(stream);
    exit(EXIT_SUCCESS);
}