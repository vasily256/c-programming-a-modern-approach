#include <stdio.h>

#define N 20

void reverse_ptr(char *p, char str[]);

int main(void)
{
    char ch, str[N], *p;

    printf("Enter a message: "); 
    for (p = str; (*p = getchar()) != '\n' && p < str + N; p++) {
    } 

    printf("Reversal is: ");
    reverse_ptr(p, str);
    printf("\n");

    return 0;
}

void reverse_ptr(char *p, char str[])
{
    for (p -= 1; p >= str; p--) 
        putchar(*p);
}
