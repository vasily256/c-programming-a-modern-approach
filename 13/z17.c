#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define STR_LEN 50

bool is_palindrome(char *message);
int read_line(char str[], int n);

int main(void)
{
    char message[STR_LEN + 1];

    printf("Enter a message: ");
    read_line(message, STR_LEN);

    if (is_palindrome(message))
        printf("Palindrome\n");
    else 
        printf("Not a palindrome\n");

    return 0;
}

bool is_palindrome(char *message)
{
    char *ptr = message + strlen(message) - 1;

    for (;;) {
        for (; !isalpha(*message); message++);
        for (; !isalpha(*ptr); ptr--);
        if (message >= ptr)
            return true;
        else if (tolower(*message++) != tolower(*ptr--))
            return false;
    }
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
