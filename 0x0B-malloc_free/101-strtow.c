#include "main.h"
#include <stdlib.h>
/**
 * get_wordCount - counts the number of words in a string
 * @str: string
 * Return: int number of words
 */

int get_wordCount(char *str)
{
	int i = 0, num_words = 0;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			if ((str[i - 1] != ' ') && i > 0)
				num_words++;
		}
	}
	if (str[i - 1] != ' ' && str[i - 1] != '\t')
	{
		num_words++;
	}
	return (num_words);
}

/**
 * strtow - splits a string into words
 * Description: puts them in an array
 * returns NULL if str == NULL or an empty string
 * @str: string
 * Return: pointer to array or NULL
 */

char **strtow(char *str)
{
	char **matrix, *tmp;
	int k = 0, len = 0, words, c = 0, start, end;
	int i = 0;

	if (str == NULL)
		return (NULL);
	while (*(str + len))
		len++;
	words = get_wordCount(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;
	return (matrix);
}
