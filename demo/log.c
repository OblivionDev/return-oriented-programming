#include <stdio.h>
#include <string.h>
#include <time.h>

char* get_time_string()
{
    time_t timestamp = time(NULL);
    char* time_string = ctime(&timestamp);
    time_string[strlen(time_string)-1] = '\0';
    return time_string;
}

void read_string_till_eof(char* buffer)
{
    int c;
    while ((c=getchar()) && c != EOF) {
        *buffer++ = c;
    }
    printf("\n");
}

void append_log(char* buffer, char* path)
{
    FILE* fp = fopen(path, "a");
    fprintf(fp, "%s: %s\n", get_time_string(), buffer);
    fclose(fp);
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: log <log file>\n");
        return 0;
    }

    char buffer[512] = {'\0'};
    char logfile_path[32] = {'\0'};

    strcat(logfile_path, argv[1]);
    if (!strcasestr(logfile_path, ".log")) {
        strcat(logfile_path, ".log");
    }

    read_string_till_eof(buffer);

    append_log(buffer, logfile_path);

    return 0;
}
