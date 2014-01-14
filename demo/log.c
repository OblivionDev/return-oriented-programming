#include <string.h>
#include "log.h"

int main(int argc, char* argv[])
{
    check_args(argc, argv);

    char buffer[512];
    char logfile_path[32];

    strcpy(logfile_path, argv[1]);
    if (!strcasestr(logfile_path, ".log"))
        strcat(logfile_path, ".log");

    read_string_till_eof(buffer);
    append_log(buffer, logfile_path);
    return 0;
}
