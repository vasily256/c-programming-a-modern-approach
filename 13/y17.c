#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 20

bool test_extension(const char *file_name,
                    const char *extension);
int read_line_up(char str[], int n);

int main(void)
{
    char file_name[LEN+1] = "", extension[LEN+1] = "";

    printf("Enter a full file-name: ");
    read_line_up(file_name, LEN);

    printf("Enter an extension: ");
    read_line_up(extension, LEN);

    if (test_extension(file_name, extension))
        printf("Matched\n");
    else
        printf("Not matched\n");

    return 0;
} 

bool test_extension(const char *f, const char *e)
{
    const char *fp = f;
    while (*f)
        f++; 
    while (*--f != '.')
        if (f == fp)
            return false;
    f++;

    return !strcmp(f, e);
}

int read_line_up(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = toupper(ch);
    str[i] = '\0';

    return i;
} 
