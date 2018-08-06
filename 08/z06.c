#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char msg[100];
    char ch;
    int i, j;

    printf("Enter message: ");
    for (i = 0; (ch = getchar()) != '\n'; i++) {
        msg[i] = ch;
    }
    
    printf("In B1FF-speak: ");
    for (j = 0; j < i; j++) {
        ch = msg[j];
        ch = toupper(ch);
        switch (ch) {
            case 'A':
                ch = '4';
                break;
            case 'B':
                ch = '8';
                break;
            case 'E':
                ch = '3';
                break;
            case 'I':
                ch = '1';
                break;
            case 'S':
                ch = '5';
                break;
            default:
                break;
        }
        printf("%c", ch);
    }
    printf("!!!!!!!!!!\n");

    return 0;
}
