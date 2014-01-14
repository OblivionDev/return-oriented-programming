#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void check_args(int count, char* vector[])
{
    if (count != 2) {
        printf("Usage: log <log file>\n");
        exit(0);
    }
}

char* get_time_string(void)
{
    time_t timestamp = time(NULL);
    char* time_string = ctime(&timestamp);
    time_string[strlen(time_string)-1] = '\0';
    return time_string;
}
