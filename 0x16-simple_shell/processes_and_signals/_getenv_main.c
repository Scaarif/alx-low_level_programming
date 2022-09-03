#include "main.h"

/**
 * main - check _getenv()
 * Return: 0 always
 */

int main(void)
{
	char *var, *name, *value, *get_name, *get_value = NULL;
	res _res = {-1, -1}, *a_res;
	int i = 0, j, len, len2, len_;

	/*get the name from the name value pair of variable*/
	get_name = "SHELLY";
	a_res = &_res;
	for (; environ[i] != NULL; i++)
	{
		var = environ[i];
		j = 0;
		for (; var[j] != '='; j++)
			;
		name = malloc(sizeof(char) * j + 1);
		if (name == NULL)
			unix_error("malloc error");
		len = j;
		len_ = len;
		for (j = 0; j < len; j++)
		       name[j] = var[j];
		name[j] = '\0';
		/*printf("char at len: %c & len + 1 %c\n", var[len], var[len + 1]);*/
		for (j = 0; var[len] != '\0'; len++, j++)
			;
		value = malloc(sizeof(char) * j);
		len2 = j;
		/*printf("char at len + 1: %c\n", var[len_ + 1]);*/
		if (value == NULL)
			unix_error("malloc error");
		for (j = 0; j < len2; j++)
			value[j] = var[len_ + 1 + j];/*skip the char =*/
		value[j] = '\0';
		if (strcmp(get_name, name) == 0)
		{
			get_value = value;
			break;
		}
		/*printf("var: %s\n", var);*/
	}
	if (get_value)
		printf("%s: %s\n", name, get_value);
	else
		printf("%s NOT FOUND\n", get_name);
	free(name);
	free(value);
	/**/
	printf("\nTEST THE FUNCTIONS VERSION\n\n");
	value = _getenv(environ, get_name, a_res);
	if (value)
		printf("%s: %s\n", get_name, value);
	else
		printf("Fns failed\n");
	free(value);
	return (0);
}
