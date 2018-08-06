#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int h, m;
    char ch;
    
    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c", &h, &m, &ch);
    
    ch = toupper(ch);
    switch (ch) {
        case 'A':
            h = h == 12 ? 0 : h;
            break;
        case 'P':
            h = h < 12 ? h + 12 : h;
            break;
    }
    
    printf("24-hour time: %d:%.2d\n", h, m);
}
