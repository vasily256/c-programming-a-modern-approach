#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int num_vowels;
    char ch;
    
    printf("Enter a sentence: ");
    num_vowels = 0;
    while ((ch = getchar()) != '\n') {
        ch = tolower(ch);
        switch (ch) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                num_vowels++;
                break;
            default:
                break;
        }
    }
    
    printf("You sentence contains %d vowels\n", num_vowels);
    
    return 0;
}
