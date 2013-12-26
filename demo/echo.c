#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 8

void echo(void)
{

    int c;
    int i;
    char buffer[BUFFER_SIZE] = {'\0'};
    for(i=0; ; i++) {
        c = getchar();

        if (c == EOF || c == '\n') {
            break;
        }

        buffer[i] = c;
    }
    printf("\nread %d bytes\n", i);
    printf("%s\n", buffer);
}

// TODO find a function that does this
void nonsense(void) {
    asm("pop %eax");
    asm("ret");
}

int main(int argc, char* argv[])
{
    time_t current_time;
    char* c_time_string;

    echo();

    return 0;
}
