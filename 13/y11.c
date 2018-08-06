#include <stdio.h>
#include <string.h>

#define LEN 20

int mstrcmp(char *s, char *t);
int mstrcmp2(char *s, char *t);
int read_line(char str[], int n);

int main(void)
{
    char s[LEN+1] = "", t[LEN+1] = "";

    printf("Enter a string 1: ");
    read_line(s, LEN);
    printf("Enter a string 2: ");
    read_line(t, LEN);

    printf("By original version: %d\n", mstrcmp(s, t));
    printf("By modified version: %d\n", mstrcmp2(s, t));
    printf("By standard library version: %d\n", strcmp(s, t));

    return 0;
} 

    // Original version

int mstrcmp(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0; 
    return s[i] - t[i];
}

    // Modified version

int mstrcmp2(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (!*s)
            return 0; 
    return *s - *t;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';

    return i;
} 
