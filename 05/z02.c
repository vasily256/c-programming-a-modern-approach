#include <stdio.h>

int main(void)
{
    int h, m;
    
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &h, &m);
    
    printf("Equivalent 12-hour time: ");
    
    if (h == 0)
        printf("12:%.2d AM\n", m);
    else if (h < 12)
        printf("%d:%.2d AM\n", h, m);
    else if (h == 12)
        printf("%d:%.2d PM\n", h, m);
    else if (h < 24)
        printf("%d:%.2d PM\n", h - 12, m);
    else
        printf("%d:%.2d AM\n", h - 12, m);
    
    return 0;
}
