// dec -> bin

#include <stdio.h>

void pb(int n);

int main(void)
{
    int n;
   
    printf("Enter a number: ");
    scanf("%d", &n);

    pb(n);
    putchar('\n');
}

void pb(int n)
{
    if (n != 0) {
        pb(n / 2);
        putchar('0' + n % 2);
    }
}
