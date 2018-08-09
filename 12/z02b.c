#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define N 20

bool is_palindrome(char *str, char *ptr);

int main(void)
{
    char ch, str[N], *ptr = str;

    printf("Enter a message: ");
    while ((ch = getchar()) != '\n' && ptr < str + N) {
        if (isalpha(ch))
            *ptr++ = tolower(ch);
    } 

    if (is_palindrome(str, ptr))
        printf("Palindrome\n");
    else 
        printf("Not a palindrome\n");

    return 0;
}

bool is_palindrome(char *str, char *ptr)
{
    while (str < ptr)
        if (*str++ != *--ptr)
            return false;

    return true;
}
