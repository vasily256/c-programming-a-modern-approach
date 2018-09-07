#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns pointer to duplicate string
char *duplicate(const char *str1)
{
    char *str2 = malloc(strlen(str1) + 1);
    return str2 != NULL ? strcpy(str2, str1) : NULL;
}

int main(void)
{
    char *str1 = "abcdefgh"; 
    char *str2 = duplicate(str1);

    if (str2 == NULL) {
        printf("malloc: allocation failed\n");
        exit(EXIT_FAILURE);
    }

    puts(str2);

    return 0;
}
