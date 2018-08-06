#include <stdio.h>
#include <string.h>

#define LEN 20

char *duplicate(const char *p);

int main(void)
{
    char str[] = "Abcd efgh";
    puts(duplicate(str));

    return 0;
}

    /* Original version

char *duplicate(const char *p)
{
    char *q;

    strcpy(q, p);
    return q;
} 
    */

    // Corrected version

char *duplicate(const char *p)
{
    static char q[LEN+1];

    strcpy(q, p);
    return q;
}
