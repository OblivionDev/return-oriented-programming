#include <stdio.h>
#include "log.h"

void append_log(char* buffer, char* path)
{
    FILE* fp = fopen(path, "a");
    fprintf(fp, "%s: %s\n", get_time_string(), buffer);
    fclose(fp);
}

void read_string_till_eof(char* buffer)
{
    int c;
    while ((c=getchar()) && c != EOF) {
        *buffer++ = c;
    }
    printf("\n");
}
