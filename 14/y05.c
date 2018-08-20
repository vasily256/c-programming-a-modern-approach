#include <stdio.h> 

#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

int main(void)
{
    char *str1 = "abcd";
    char *str2 = "0123";

    int i = 0;
    printf("(a) %c\n", TOUPPER(str1[++i]));

    i = 0;
    printf("(b) %c\n", TOUPPER(str2[++i]));

    return 0;
}
