#include <stdio.h>

#define LEN 20

void remove_filename(char *url);
int read_line(char str[], int n);

int main(void)
{
    char url[LEN+1] = "";

    printf("Enter URL: ");
    read_line(url, LEN);
    remove_filename(url);

    puts(url);

    return 0;
} 

void remove_filename(char *url)
{
    char *p = url;

    while(*url)
        url++;

    while(*--url != '/')
        if (url == p)
            return;

    *url = '\0';
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
