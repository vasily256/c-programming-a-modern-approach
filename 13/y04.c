#include <stdio.h>
#include <ctype.h> 

#define LEN 20

int read_line(char msg_str[], int n);
int read_line_a(char msg_str[], int n);
int read_line_b(char msg_str[], int n);
int read_line_c(char msg_str[], int n);
int read_line_d(char msg_str[], int n);

int main(void)
{
    char msg_str[LEN+1] = "";

    printf("(a): ");
    read_line_a(msg_str, LEN);
    puts(msg_str);

    printf("(b): ");
    read_line_b(msg_str, LEN);
    puts(msg_str);

    printf("(c): ");
    read_line_c(msg_str, LEN);
    puts(msg_str);

    printf("(d): ");
    read_line_d(msg_str, LEN);
    puts(msg_str);

    return 0;
}

// Original function

int read_line(char msg_str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            msg_str[i++] = ch;
    msg_str[i] = '\0';

    return i;
}

// (a) Skips white spaces before beginning to store input characters

int read_line_a(char msg_str[], int n)
{
    int ch, i = 0; 

    scanf(" ");
    while ((ch = getchar()) != '\n')
        if (i < n)
            msg_str[i++] = ch;
    msg_str[i] = '\0';

    return i;
}

// (b) Stops reading at the first white-space character

int read_line_b(char msg_str[], int n)
{
    int ch, i = 0;

    while (!isspace(ch = getchar()))
        if (i < n)
            msg_str[i++] = ch;
    msg_str[i] = '\0';

    return i;
}

// (c) Stops readint at the first new-line character, then stores the new-line character in the string

int read_line_c(char msg_str[], int n)
{
    int ch, i = 0;

    do {
        ch = getchar();
        if (i < n)
            msg_str[i++] = ch;
    } while (ch != '\n');
    msg_str[i] = '\0';

    return i;
}

// (d) Leaves behind characters that it doesn't have room to store

int read_line_d(char msg_str[], int n)
{
    int ch, i;

    for (i = 0; i < n; i++) {
        ch = getchar();
        if (ch == '\n')
            break;
        msg_str[i] = ch;
    }
    msg_str[i] = '\0';

    return i;
}
