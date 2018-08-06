#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int scr_val = 0;
    
    printf("Enter a word: ");
    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);
        switch (ch) {
            case 'A': case 'E': case 'I': case 'L': case 'N': case 'O': case 'R': case 'S': case 'T': case 'U':
                scr_val += 1;
                break;
            case 'D': case 'G':
                scr_val += 2;
                break;
            case 'B': case 'C': case 'M': case 'P':
                scr_val += 3;
                break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                scr_val += 4;
                break;
            case 'K':
                scr_val += 5;
                break;
            case 'J': case 'X':
                scr_val += 8;
                break;
            case 'Q': case 'Z':
                scr_val += 10;
                break;
            default:
                break;
        }
    }
    printf("Scrabble value: %d\n", scr_val);
    
    return 0;
}
