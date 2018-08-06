#include <stdio.h>

#define N 80

void encrypt(char *message, int shift);
int read_line(char str[], int n);

int main(void)
{
    int shift, i, j;
    char str[N + 1];
    
    printf("Enter a message to be encrypted: ");
    read_line(str, N);
    printf("Enter shift amount: ");
    scanf("%d", &shift);
    
    printf("Encrypted message: %s\n", encrypt(str, shift));
    
    return 0;
}

void encrypt(char *message, int shift)
{
    for (j = 0; j < i; j++) {
        if (ch[j] >= 'a' && ch[j] <= 'z') {
            ch[j] = ((ch[j] - 'a') + n) % 26 + 'a';
        } else if (ch[j] >= 'A' && ch[j] <= 'Z') {
            ch[j] = ((ch[j] - 'A') + n) % 26 + 'A';
        }
    }
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';

    return i;
}
