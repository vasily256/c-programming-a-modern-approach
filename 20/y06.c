#include <stdio.h>

unsigned short swap_bytes(unsigned short i)
{
    return i << sizeof(i) * 4 | i >> sizeof(i) * 4;
}

int main(void)
{
    unsigned short i;

    printf("Enter a hexadecimal number (up to four digits): ");
    scanf("%hx", &i);
    printf("Number with bytes swapped: %hx\n", swap_bytes(i));

    return 0;
}
