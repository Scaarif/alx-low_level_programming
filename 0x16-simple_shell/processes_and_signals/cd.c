#include "main.h"

int parse_line(char *buf, char del, char **argv)
{
	char *delim;
	int argc, bg;

	buf[strlen(buf) - 1] = del;/* replace trailing /n with space/delim */
	while (*buf && (*buf == ' '))
		buf++; /* ignore leading spaces; advance buf to 1st char */
	/* Build the argv array */
	argc = 0;
	while ((delim = strchr(buf, del)))/*del*/
	{/*strchr returns pointer to 1st occurrence of ' ' in buf or NULL*/
		argv[argc++] = buf;
		*delim = '\0'; /*terminate 1st string in argv*/
		buf = delim + 1; /*advance in buf - to start of next string*/
		while (*buf && ((*buf == del) || (*buf == ' ')))
			buf++; /*ignore leading spaces*/
	}
	argv[argc] = NULL; /*last string*/
	if (argc == 0)
		return (1); /* ignore blank cmd(line) */
	/*is the job a back or foreground job?*/
	bg = (*argv[argc - 1] == '&');/*true = 1, else 0*/
	if (bg)
		argv[--argc] = NULL; /*remove the '&' from array*/
	return (bg);
}

/**
 * main - test parse_line
 * @ac: args count
 * @av: args array
 * Return: 0 Always
 */
int main(void)
{
	char buf[MAXLINE], *argv[MAXARGS], cmdline[MAXLINE], del = '&', dels[PATH_S];
	char *commands[MAXARGS], command[PATH_S];
	int i, j;
	
	printf("#cisfun$ ");
	Fgets(cmdline, MAXLINE, stdin);
	strcpy(buf, cmdline);
	check_for_delims(buf, "&|;", dels);
	for (i = 0; dels[i] != '\0'; i++)
		printf("del: %c\n", dels[i]);
	parse_line(buf, del, commands);/*build commands array*/
	printf("Commands: \n");
	for (i = 0; commands[i] != NULL; i++)
	{
		for (j = 0; (command[j] = commands[i][j]) != '\0'; j++)
			;
		/*add a new line char to each command b4 termination?*/
		command[j++] = '\n';
		command[j] = '\0';
		printf("command_str:%s", command);
		/*get each command's argv array*/
		del = ' ';
		strcpy(buf, command);
		parse_line(buf, del, argv);/*build argv array for a single command*/
		/*printf("Command array string: %s\n", *argv);*/
		printf("Command array strings: \n");
		for (j = 0; argv[j] != NULL; j++)
			printf("%s\n", argv[j]);/*print the array tokens*/
		/*printf("%s\n", commands[i]);*/
	}
	return (0);
}

