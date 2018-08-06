#include <stdio.h>

#define N 80

int main(void)
{
    int n, i, j;
    char ch[N];
    
    printf("Enter a message to be encrypted: ");
    for (i = 0; i < N; i++) {
        ch[i] = getchar();
        if (ch[i] == '\n') {
            break;
        }
    }
    
    printf("Enter shift amount: ");
    scanf("%d", &n);
    
    for (j = 0; j < i; j++) {
        if (ch[j] >= 'a' && ch[j] <= 'z') {
            ch[j] = ((ch[j] - 'a') + n) % 26 + 'a';
        } else if (ch[j] >= 'A' && ch[j] <= 'Z') {
            ch[j] = ((ch[j] - 'A') + n) % 26 + 'A';
        }
    }
    
    printf("Encrypted message: ");
    for (j = 0; j <= i; j++) {
        putchar(ch[j]);
    }
    
    return 0;
}
