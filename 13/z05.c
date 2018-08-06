// Returns sum of command-line arguments

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int sum = 0;

    while (--argc > 0)
        sum += atoi(argv[argc]);
    printf("Total: %d\n", sum);

    return 0;
}
