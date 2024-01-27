#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <sys/stat.h>
#include <sys/types.h>

void syslog_error(const char *message) {
    syslog(LOG_ERR, "%s", message);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        syslog_error("Please provide the file path and the text string.");
        exit(EXIT_FAILURE);
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];
    

    FILE *file = fopen(writefile, "w");
    if (file == NULL) {
        syslog_error("Failed to open file for writing.");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s\n", writestr);
    fclose(file);

    openlog("writer", LOG_PID | LOG_NDELAY, LOG_USER);

    syslog(LOG_DEBUG, "Writing '%s' to '%s'", writestr, writefile);

    closelog();

    printf("File '%s' created successfully with content '%s'\n", writefile, writestr);

    return 0;
}
