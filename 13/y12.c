#include <stdio.h>
#include <string.h>

#define LEN 20
#define EXT 3

void get_extension(const char *file_name, char *extension);
int read_line(char str[], int n);

int main(void)
{
    char file_name[LEN+1] = "";
    char extension[EXT+1] = "";

    printf("Enter a file name: ");
    read_line(file_name, LEN);

    get_extension(file_name, extension); 
    printf("Extension of the file: %s\n", extension);

    return 0;
} 

void get_extension(const char *file_name, char *extension)
{
    strcpy(extension, file_name + strlen(file_name) - 3);
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
