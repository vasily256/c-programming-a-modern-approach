#include <stdio.h>
#include <string.h>

#define STR_LEN 50

void reverse(char *message);
int read_line(char str[], int n);

int main(void)
{
    char message[STR_LEN + 1];

    printf("Enter a message: ");
    read_line(message, STR_LEN);

    reverse(message);
    printf("Reversal is: %s\n", message);

    return 0;
}

void reverse(char *msg_left)
{
    char temp;
    char *msg_right = msg_left + strlen(msg_left) - 1;

    for (; msg_left < msg_right; msg_right--, msg_left++) {
        temp = *msg_right;
        *msg_right = *msg_left;
        *msg_left = temp;
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
