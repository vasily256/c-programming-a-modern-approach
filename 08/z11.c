#include <stdio.h>
#define N 15

int main(void)
{
    char n[N];
    int i, j;
    
    printf("Enter phone number: ");
    for (j = 0; (n[j] = getchar()) != '\n' && j < N; j++) {
    }
    
    for (i = 0; i < j; i++) {
        switch (n[i]) {
            case 'A': case 'B': case 'C':
                n[i] = '2';
                break;
            case 'D': case 'E': case 'F':
                n[i] = '3';
                break;
            case 'G': case 'H': case 'I':
                n[i] = '4';
                break;
            case 'J': case 'K': case 'L':
                n[i] = '5';
                break;
            case 'M': case 'N': case 'O':
                n[i] = '6';
                break;
            case 'P': case 'R': case 'S':
                n[i] = '7';
                break;
            case 'T': case 'U': case 'V':
                n[i] = '8';
                break;
            case 'W': case 'X': case 'Y':
                n[i] = '9';
                break;
            default:
                break;
        }
    }
    
    printf("In numeric form: ");
    for (i = 0; i < j; i++) {
        putchar(n[i]);
    }
    printf("\n");
    
    return 0;
}
