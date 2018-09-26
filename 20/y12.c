#include <stdio.h>

/* Fixed function in ex.12 of ch.20 */
unsigned short create_short(unsigned char high_byte,
                            unsigned char low_byte)
{
    /* return high_byte << 8 + low_byte; */
    return ((unsigned short) high_byte << 8) + low_byte;
}

int main(void)
{
    unsigned char i, j;
    unsigned short k;

    printf("Enter two two-digit hexadecimal values: ");
    scanf("%hhx %hhx", &i, &j);
    k = create_short(i, j);
    printf("In hexadecimal: %x\n",  k);

    return 0;
}
