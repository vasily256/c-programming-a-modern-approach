#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 50

void reverse_name(char *name);
int read_line(char str[], int n);

int main(void)
{
    char name[MAX_LEN+1] = "";
    
    printf("Enter a first and last name: ");
    read_line(name, MAX_LEN); 
    reverse_name(name);
    puts(name);
    
    return 0;
}

void reverse_name(char *name)
{
    char initial[2+1] = " .", *str = name;

    while (isspace(*str))     // Skips extra spaces
        str++;
    initial[0] = *str;             // Saves first initial 
    while (!isspace(*str))    // Skips non-space characters
        str++;
    while (isspace(*str))     // Skips extra spaces
        str++;

    strcpy(name, str);
    strcat(name, ", ");
    strcat(name, initial); 
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
