#include <stdio.h>

int main(void)
{
    union {
        struct {
            unsigned int eax, ebx, ecx, edx;
        } dword;
        struct {
            unsigned short ax, a0, bx, b0, cx, c0, dx, d0;
        } word;
        struct {
            unsigned char al, ah, a0, a1, bl, bh, b0, b1, cl, ch, c0, c1, dl, dh, d0, d1;
        } byte;
    } u;

    /* Checking size of types */
    printf("sizeof(unsigned char) = %d\n", (int) sizeof(unsigned char));
    printf("sizeof(unsigned short) = %d\n", (int) sizeof(unsigned short));
    printf("sizeof(unsigned int) = %d\n", (int) sizeof(unsigned int));

    printf("Enter four four-digit hexadecimal values: ");
    unsigned int *p0 = &u.dword.eax;
    for (int i = 0; i < 4; i++)
        scanf(" %x", p0 + i);
    putchar('\n');

    printf("     EAX      EBX      ECX      EDX\n");
    unsigned int *p1 = &u.dword.eax;
    for (int i = 0; i < 4; i++)
        printf("%x ", *(p1 + i));
    putchar('\n');

    printf("\n      AX       BX       CX       DX\n");
    unsigned short *p2 = &u.word.ax;
    for (int i = 0; i < 8; i++)
        if (i % 2 == 0)
            printf("%8hx ", *(p2 + i));
    putchar('\n');

    printf("\n      AL       BL       CL       DL\n");
    unsigned char *p3 = &u.byte.al;
    for (int i = 0; i < 16; i++)
        if (i % 4 == 0)
            printf("%8hx ", *(p3 + i));
    putchar('\n');

    printf("    AH       BH       CH       DH\n");
    unsigned char *p4 = &u.byte.al;
    for (int i = 0; i < 16; i++)
        if (i % 4 == 1)
            printf("%6hx   ", *(p4 + i));
    putchar('\n');


    return 0;
}

