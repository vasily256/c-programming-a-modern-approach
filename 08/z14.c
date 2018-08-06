#include <stdio.h>

#define N 64

int main(void)
{
    char ch[N + 1] = {' '};
    char ch_t;
    int i, j, k, m;
    
    printf("Enter a sentence: ");
    for (i = 1; i <= N; i++) {
        ch[i] = getchar();
        if (ch[i] == '.' || ch[i] == '!' || ch[i] == '?') {
            ch_t = ch[i];
            break;
        }
    }
    
    printf("Reversal of sentence:");
    for (j = m = i - 1; j >= 0; j--) {
        if (ch[j] == ' ') {
            for (k = j; k <= m; k++) {
                putchar(ch[k]);
            }
            m = j - 1;
        }
    }
    printf("%c\n", ch_t);
    
    return 0;
}
