#include <stdio.h>

#define LEN 20

int count_spaces(const char *s);
int count_spaces2(const char *s);
int read_line(char str[], int n);

int main(void)
{
    char s[LEN+1] = "";

    printf("Enter a string: ");
    read_line(s, LEN);

    printf("Number of spaces by original version: %d\n",
            count_spaces(s));
    printf("Number of spaces by condensed version: %d\n",
            count_spaces2(s));

    return 0;
} 

    // Original version

int count_spaces(const char *s)
{
    int count = 0;

    for (; *s != '\0'; s++)
        if (*s == ' ')
            count++;
    return count;
}

    // Condensed version

int count_spaces2(const char *s)
{
    int count = 0;

    while (*s)
        if (*s++ == ' ')
            count++;
    return count;
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
