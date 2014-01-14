////   io.c   ////

// Appends the buffer to the log-file specified by the path
void append_log(char* buffer, char* path);

// Reads an input string to the buffer until EOF is read
void read_string_till_eof(char* buffer);



////   util.c   ////

// Checks the program arguments
void check_args(int count, char* vector[]);

// Returns a string that describes the current timestamp
char* get_time_string(void);
