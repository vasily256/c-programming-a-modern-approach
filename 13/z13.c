#include <stdio.h>

#define N 80

void encrypt(char *message, int shift);
int read_line(char str[], int n);

int main(void)
{
    int shift;
    char message[N + 1];
    
    printf("Enter a message to be encrypted: ");
    read_line(message, N);
    printf("Enter shift amount: ");
    scanf("%d", &shift);

    encrypt(message, shift); 
    printf("Encrypted message: %s\n", message);
    
    return 0;
}

void encrypt(char *message, int shift)
{
    for (; *message; message++) {
        if (*message >= 'a' && *message <= 'z') {
            *message = ((*message - 'a') + shift) % 26 + 'a';
        } else if (*message >= 'A' && *message <= 'Z') {
            *message = ((*message - 'A') + shift) % 26 + 'A';
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
