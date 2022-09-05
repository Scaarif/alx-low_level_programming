#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>

#define	MAXLINE	 8192  /* Max text line length */
#define MAXJOBS    16
#define PATH_S 1024
#define MAXARGS 128


extern char **environ;/*an external (global) variable - defined in Unix*/
int success;

typedef void handler_t(int);

/** STRUCTURES **/

/**
 * struct env_variable - response structure
 * for the get_name function, gets name of a variable
 * @var_index: index of the variable(in envp)
 * @val_index: string pointer to variable value
 */
typedef struct env_variable
{
	int var_index;
	int val_index;
} res;

/**
 * struct path_node - PATH directories linked list node
 * @dir: the directory(as path)
 * @next: the next dir in list
 */
typedef struct path_node
{
	char *dir;
	struct path_node *next;
} d_t;

/** WRAPPER FNS **/

int unix_error(const char *msg);
pid_t Fork(void);
void Execve(const char *filename, char *const argv[], char *const envp[]);
unsigned int wakeup(unsigned int secs);
char *Fgets(char *str, int size, FILE *stream);
int Kill(pid_t pid, int sig);
unsigned int Sleep(unsigned int secs);
void sigint_handler(int sig);

/* helper functions - p_writes */
int get_name(char **env, char *name_, res *_res);
char *_getenv(char **env, char *name, res *_res);
d_t *create_path_list(char *dir_str, d_t **head);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(char *name);
void evaluate_command_line(char *cmdline, d_t *head);
char *parse_path(d_t **head, char *file);
void print_pathlist(d_t **head);
int _write(char *buf, char *str, char *msg);
int builtin_command(char **argv);
int _cd(char **av);
char *check_for_delims(char *cmdline, char *delims, char *res);
int _strlen(char s[]);
void set_success(int i);
char *format_command(char *cmd, char *command);


/* safe I/O functions for signal handlers */
ssize_t sio_puts(char s[]);
ssize_t Sio_puts(char *s);
void sio_error(char *s);

/* sigprocmask & sigaction wrappers */
handler_t *Signal(int signum, handler_t *handler);
void Sigfillset(sigset_t *set);
void Sigemptyset(sigset_t *set);
void Sigaddset(sigset_t *set, int signum);
void Sigprocmask(int how, const sigset_t *set, sigset_t *oldset);

/* JOBS */



#endif /*MAIN_H*/

