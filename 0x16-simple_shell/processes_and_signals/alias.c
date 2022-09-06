#include "main.h"

/**
 * _alias - an implementation of alias()
 * @argv: pointer to array of args
 * Return: ALIAS array? (in env)
 */
char *_alias(char **argv)
{
	int i = 0;
	res _res = {-1, -1}, *res = &_res;
	alias_t alias_arr[MAXARGS];/*an array of alias(s)*/
	char buf[PATH_S];
	char *alias_str = _getenv(environ, "ALIAS", res);

	/* handle alias */
	if (argv[1] == NULL)
	{
		/*get ALIAS from env if set - kinda like PATH*/
		alias_arr = build_alias_array(alias_str);
		for (; alias_arr[i] != NULL; i++)
			_write(buf, alias_arr[i]->name, alias_arr[i]->value);
	}
	/* handle alias name [name2 ...] - prints each alias (given the name) */
	/*go through alias_array & if name, print alias(name='value')*/
	/* setting alias - &/ creating a new alias */
	/*go through alias_array & if name, reset the value, else, add name=value pair to array */
	/**** to reset alias's value or create a new alias - the ALIAS str'll need re-writing *****/
	alias_str = recreate_string_from_array(alias_arr);
	/*to demarcate alias(s), use a ':' like in PATH */
	/*finally*/ _setenv("ALIAS", alias_str, 1);/*allow overwrite*/
}