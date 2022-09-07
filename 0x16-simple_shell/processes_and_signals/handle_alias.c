#include "main.h"

/* return index of last alias (b4 NULL) */
int build_alias_array(char *alias_str, alias_t *arr)
{

}

char *recreate_alias_string(alias_t arr)
{

}
/* return index of the name we are searching for or -1 if absent*/
int traverse_array(alias_t arr, char *name)
{

}

/**
 * rebuild_command_line - recreate original command-line
 * for formatting, before building the alias_array
 * @argv: pointer to command args
 * @buffer: buffer to hold the rebuilt & formatted string
 * Return: rebuilt command-line string
 */
char *rebuild_command_line(char **argv, char *buffer)
{
	int i = 0, j = 0;
	char delims[3], bufcpy[MAXLINE];

	for (; argv[i] != NULL; i++)
	{
		for (; (buffer[j] = argv[i][j]) != '\0'; j++)
			;
		buffer[j++] = ' ';/*replace terminator with space*/
	}
	buffer[j] = '\0';/*terminate string as had been typed in*/
	/* format string to demarcate alias(s) / alias-names */
	check_for_delims(buffer, "'", delims);
	strcpy(bufcpy, buffer);
	if (_strlen(delims))/*command to create alias(s)*/
	{/*format with respect to name='value': pairs*/
		for (i = 0, j = 0; bufcpy[i] != '\0'; i++, j++)
		{
			if (bufcpy[i - 1] == '\'')
				buffer[j] = ':';
			else if ((bufcpy[i] == '[')|| (bufcpy[i] == ']'))
				--j;/*skip it*/
			else
				buffer[j] = bufcpy[i];
		}
		buffer[j++] = '\n';
		buffer[j] = '\0';
	}
	else/*command to list given names*/
	{/*format wrt name (i.e. just remove the [])*/
		for (i = 0, j = 0; bufcpy[i] != '\0'; i++, j++)
		{
			if ((bufcpy[i] == '[')|| (bufcpy[i] == ']'))
				--j;/*skip them so buffer is made up of just names*/
			else
				buffer[j] = bufcpy[i];
		}
		buffer[j++] = '\n';
		buffer[j] = '\0';
	}
	return (buffer);
}

/**
 * _alias - an implementation of alias()
 * @argv: pointer to array of args
 * @status: pointer to exit_status flag
 * Return: ALIAS array? (in env)
 */
void _alias(char **argv, int *status)
{
	int i, j, k, last_a;
	res _res = {-1, -1}, *res = &_res;
	alias_t alias_arr[MAXARGS], *arr = &alias_arr;/*an array of alias(s)*/
	char buf[PATH_S], buffer[MAXLINE], delims[3], *_argv[MAXARGS];
	char buffer_cpy[MAXLINE], *alias_str = _getenv(environ, "ALIAS", res);

	/* handle alias */
	if (argv[1] == NULL)
	{
		if (alias_str)
			last_a = build_alias_array(alias_str, arr);
		else
			alias_arr[0] = NULL;
		for (i = 0; alias_arr[i] != NULL; i++)
			_write(buf, alias_arr[i]->name, alias_arr[i]->value);
	}
	else
	{
		rebuild_command_line(argv, buffer);/*formats buffer - cmd_str*/
		check_for_delims(buffer, ":", delims);
		strcpy(buffer_cpy, buffer);
		/* handle alias name [name2 ...] - prints each alias (given the name */
		/*go through alias_arr & if name, print alias(name='value')*/
		if (!_strlen(delims))
		{
			parse_line(buffer_cpy, _argv, ' ');
			for (i = 1; _argv[i] != NULL; i++)/*_argv[0] = alias(command)*/
			{
				for (j = 0; alias_arr[j] != NULL; j++)
				{
					if (strcmp(alias_arr[j]->name, _argv[i]) == 0)
						_write(buf, alias_arr[j]->name, alias_arr[j]->value);
					break;
				}
			}
		}
		else
		{
			/* setting alias value - &/ creating a new alias */
			/*go through alias_arr & if name, reset the value, else, add name='value' pair to array*/
			parse_line(buffer_cpy, _argv, ':');/*first element: alias + name='value'*/
			for (i = 0; argv[i] != NULL; i++)
			{
				for (j = 0, k = 0; argv[i][j] != '\0'; j++)
				{
					if (argv[i][j] != '[' && argv[i][j] != ']')
						buf[k++] = argv[i][j];
				}
				buf[k] = '\0';/*terminate buf - essentailly name*/
				for (j = 0; alias_arr[j] != NULL; j++)
				{/*temporary buf - format name(remove [ & ])*/
					if (strcmp(alias_arr[j]->name, buf) == 0)
						alias_arr[j]->value = 
					break;
				}
			}
		}
	}
	/*rewrite alias_str and set ALIAS's value in env*/
	alias_str = recreate_alias_string(alias_arr);
	/*demarcate alias(s) with ':' like in PATH*/
	_setenv("ALIAS", alias_str, 1);/*set ALIAS to updated value*/
}
