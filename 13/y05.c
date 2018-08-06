#include <stdio.h>
#include <ctype.h> 

#define LEN 20

int read_line(char str[], int n);
void capitalize_a(char str[]);
void capitalize_b(char *str);

int main(void)
{
    char str[LEN+1] = "";

    printf("(a) Using array subscripting:\n");
    read_line(str, LEN);
    capitalize_a(str);
    puts(str);

    printf("(b) Using pointer arithmetic:\n");
    read_line(str, LEN);
    capitalize_b(str);
    puts(str);

    return 0;
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

// (a) Using array subscripting

void capitalize_a(char str[])
{
    for (int i = 0; str[i] = toupper(str[i]); i++)
        ;
}

// (b) Using pointer arithmetic

void capitalize_b(char *str)
{
    for (; *str = toupper(*str); str++)
        ;
}
