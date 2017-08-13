#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>


int main()
{
    /* Our process ID and Session ID */
    pid_t pid, sid;

    /* Fork off the parent process */
    pid = fork();
    if (pid < 0) {
            exit(EXIT_FAILURE);
    }
    /* If we got a good PID, then
       we can exit the parent process. */
    if (pid > 0) {
            exit(EXIT_SUCCESS);
    }

    /* Change the file mode mask */
    umask(0);

    /* Open logs here */
    setlogmask(LOG_UPTO (LOG_DEBUG));
    openlog("upgrade-daemon", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_DAEMON);
    char* unformatted_log_string = "failed to %s";

    /* Create a new SID for the child process */
    sid = setsid();
    if (sid < 0) {
            /* Log the failure */
            syslog(LOG_ERR, unformatted_log_string, "set SID");
            exit(EXIT_FAILURE);
    }

    /* Change the current working directory */
    if ((chdir("/")) < 0) {
            /* Log the failure */
            syslog(LOG_ERR, unformatted_log_string, "change directory");
            exit(EXIT_FAILURE);
    }

    /* Close out the standard file descriptors */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    /* Daemon-specific initialization goes here */

    while (1) {
        if(system("pacman -Syu --noconfirm") == -1){
            syslog(LOG_ERR, unformatted_log_string, "perform full system upgrade");
        }
        else{
            syslog(LOG_INFO, "full system upgrade performed successfully");
        }
        /* wait 3 seconds */
        sleep(3600);
    }

    closelog();
    exit(EXIT_SUCCESS);
}
