#include <stdio.h>
#include <string.h>

#define LEN 50

void build_index_url(const char *domain, char *index_url);
int read_line(char str[], int n);

int main(void)
{
    char domain[LEN+1] = "";
    char index_url[LEN+1] = "";

    printf("Enter a domain name: ");
    read_line(domain, LEN);

    build_index_url(domain, index_url);
    printf("URL: %s\n", index_url);

    return 0;
} 

void build_index_url(const char *domain, char *index_url)
{
    char *begin = "http://www.";
    char *end = "/index.html";

    strcat(strcat(strcpy(index_url, begin), domain), end); 
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
