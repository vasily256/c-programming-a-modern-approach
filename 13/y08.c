#include <stdio.h>
#include <string.h>

#define LEN 20

int main(void)
{
    char str[LEN+1] = "";

    strcpy(str, "tire-bouchon");
    puts(str);                      // tire-bouchon
    strcpy(&str[4], "d-or-wi");
    puts(str);                      // tired-or-wi
    strcat(str, "red?");
    puts(str);                      // tired-or-wired

    return 0;
}
