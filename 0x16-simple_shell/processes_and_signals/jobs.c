#include "main.h"

/* Job states */
#define UNDEF 0 /* undefined */
#define FG 1    /* running in foreground */
#define BG 2    /* running in background */
#define ST 3    /* stopped */


/***********************************************
 * Utility routines that manipulate the job list
 **********************************************/

/* clearjob - clear the entries in a job */
void clearjob(struct job_t *job) {
    job->pid = 0;
    job->state = UNDEF;
    job->cmdline[0] = '\0';
}

/* initjobs - initialize the job list */
void initjobs(struct job_t *jobs) {
    int i;

    for (i = 0; i < MAXJOBS; i++)
	clearjob(&jobs[i]);
}

/* addjob - add a job to the job list */
int addjob(struct job_t *jobs, pid_t pid, int state, char *cmdline) 
{
    int i;
    
    for (i = 0; i < MAXJOBS; i++) {
	if (jobs[i].pid == 0) {
	    jobs[i].pid = pid;
	    jobs[i].state = state;
	    strcpy(jobs[i].cmdline, cmdline);
	    return 1;
	}
    }
    printf("Tried to create too many jobs\n");
    return 0;
}

/* deletejob - delete a job from the job list */
int deletejob(struct job_t *jobs, pid_t pid) 
{
    int i;

    for (i = 0; i < MAXJOBS; i++) {
	if (jobs[i].pid == pid) {
	    clearjob(&jobs[i]);
	    return 1;
	}
    }
    return 0;
}

/* updatejob - update the state of a job with PID=pid */
int updatejob(struct job_t *jobs, pid_t pid, int state) 
{
    int i;

    for (i = 0; i < MAXJOBS; i++) {
	if (jobs[i].pid == pid) {
	    jobs[i].state = state;
	    return 1;
	}
    }
    printf("Job %d not found\n", pid);
    return 0;
}