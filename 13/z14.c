#include <stdio.h>
#include <ctype.h>

#define N 80

int main(void)
{
    short n[26] = {0}, i;
    char ch;
    
    printf("Enter first word: ");
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            ch = tolower(ch);
            n[ch - 'a']++;
        }
    }
    
    printf("Enter second word: ");
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            ch = tolower(ch);
            n[ch - 'a']--;
        }
    }
    
    for (i = 0; i < 26; i++) {
        if (n[i]) {
            printf("The words are not anagrams\n");
            return 0;
        }
    }
    printf("The words are anagrams\n");
    
    return 0;
}
