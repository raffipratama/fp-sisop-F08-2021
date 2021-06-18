#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <syslog.h>
#include <time.h>
#include <wait.h>



int main(){
  pid_t pid, sid;
    pid = fork();
 
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
 
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }
 
    umask(0);
 
    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }
}
