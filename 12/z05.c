#include <stdio.h>

#define N 64

int main(void)
{
    char ch[N + 1] = {' '};
    char *ptr0 = &ch[1], *ch_t, *ptr1, *ptr2, *ptr3;
    
    printf("Enter a sentence: ");
    for (; ptr0 <= ch + N; ptr0++) {
        *ptr0 = getchar();
        if (*ptr0 == '.' || *ptr0 == '!' || *ptr0 == '?') {
            ch_t = ptr0;
            break;
        }
    }
    
    printf("Reversal of sentence:");
    for (ptr1 = ptr2 = --ptr0; ptr1 >= ch; ptr1--) {
        if (*ptr1 == ' ') {
            for (ptr3 = ptr1; ptr3 <= ptr2; ptr3++) {
                putchar(*ptr3);
            }
            ptr2 = ptr1 - 1;
        }
    }
    printf("%c\n", *ch_t);
    
    return 0;
}
