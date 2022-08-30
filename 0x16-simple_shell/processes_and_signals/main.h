#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

#define	MAXLINE	 8192  /* Max text line length */
#define MAXJOBS    16

extern char **environ;/*an external (global) variable - defined in Unix*/

typedef void handler_t(int);


void unix_error(char *msg);
pid_t Fork(void);
void Execve(const char *filename, char *const argv[], char *const envp[]);
unsigned int wakeup(unsigned int secs);
char *Fgets(char *str, int size, FILE *stream);
int Kill(pid_t pid, int sig);
unsigned int Sleep(unsigned int secs);
void sigint_handler(int sig);

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

