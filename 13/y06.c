#include <stdio.h>

#define LEN 20

void censor(char str[]);
int read_line(char str[], int n);

int main(void)
{
    char str[LEN+1] = "";

    printf("Enter a string: ");
    read_line(str, LEN);
    censor(str);
    puts(str);

    return 0;
}

// replaces 'foo' by 'xxx'

void censor(char str[])
{
    int i = 0;
    while (str[i])
        if (str[i++] == 'f')
            if (str[i++] == 'o')
                if (str[i++] == 'o')
                    str[i] = str[i-1] = str[i-2] = 'x';
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
