#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define N 20

bool is_palindrome(int n, char a[]);

int main(void)
{
    char ch, str[N];

    printf("Enter a message: ");

    int i = 0;
    while ((ch = getchar()) != '\n' && i < N) {
        if (isalpha(ch))
            str[i++] = tolower(ch);
    } 
    
    if (is_palindrome(i, str))
        printf("Palindrome\n");
    else 
        printf("Not a palindrome\n");

    return 0;
}

bool is_palindrome(int n, char a[])
{
    for (int i = 0; i <= n--; i++)
        if (a[i] != a[n])
            return false;

    return true;
}
