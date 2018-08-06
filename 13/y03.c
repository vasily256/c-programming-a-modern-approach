// If the user enters 12abc34 56def78 the values of i, s and j will be 12 abc34 56 respectively
#include <stdio.h>

#define N 20

int main(void)
{
    int i, j;
    char s[N] = "";

    printf("Enter characters: ");
    scanf("%d%s%d", &i, s, &j);

    printf("%d %s %d\n", i, s, j);

    return 0;
}
