#include "main.h"
#include <stdlib.h>

/**
 * strtow - splits a string into words
 * Description: puts them in an array
 * returns NULL if str == NULL or an empty string
 * @str: string
 * Return: pointer to array or NULL
 */

char **strtow(char *str)
{
	char *p, *word;
	int i = 0, num_words = 0, len_words = 0, j = 0;

	if (str == NULL || str == "")
		return (NULL);
	for (; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			if ((str[i - 1] != ' ') && i > 0)
				num_words++;
		}
	}
	/*get len of these words for memory alloc to the array*/
    for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			len_words++;
		}
	}
    if (str[i - 1] != ' ' && str[i - 1] != '\t')
        num_words++;
    /*account for null terminating chars at end of each word*/
    len_words += num_words;
    p = malloc(sizeof(char) * len_words);
	if (p == NULL)
		return (NULL);
    /*add the words to the array*/
    for (i = 0; ; i++)
	{
		while(str[i] != ' ' && str[i] != '\t' && j < len_words)
		{
			*(word + j) = str[i];
		}
        
	}
	return (p);
}
yy