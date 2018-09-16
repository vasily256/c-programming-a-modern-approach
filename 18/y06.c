#include <stdio.h>

// original version
void print_error(const char *message)
{
    int n = 1;
    printf("Error %d: %s\n", n++, message);
}

// fixed version
void print_error2(const char *message)
{
    static int n = 1;
    printf("Error %d: %s\n", n++, message);
}

int main(void)
{
    for (int i = 0; i < 3; i++)
        print_error("");

    for (int i = 0; i < 3; i++)
        print_error2("");

    return 0;
}
