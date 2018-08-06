#include <stdio.h>

#define N 20

void reverse_scr(int n, char str[]);
void reverse_ptr(char *p, char str[]);

int main(void)
{
    char ch, str[N], *p;
    int i;

    printf("(a) Enter a message: ");
    for (i = 0; (ch = getchar()) != '\n' && i < N; i++)
        str[i] = ch;

    printf("Reversal is (using array subscripting): ");
    reverse_scr(i, str);
    printf("\n");

    printf("(b) Enter a message: ");

    for (p = str; (*p = getchar()) != '\n' && p < str + N; p++) {
    } 

    printf("Reversal is (using pointer arithmetic): ");
    reverse_ptr(p, str);
    printf("\n");

    return 0;
}

//  (a) using array subscripting:

void reverse_scr(int n, char str[])
{
    for (int i = n - 1; i >= 0; i--)
        putchar(str[i]);
}

//  (b) using pointer arithmetic:

void reverse_ptr(char *p, char str[])
{
    for (p -= 1; p >= str; p--) 
        putchar(*p);
}
