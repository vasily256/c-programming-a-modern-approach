#include <stdio.h>

int main(void)
{
    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, total;
    
    printf("Enter all 12 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12);
    
    total = 3 * (i1 + i3 + i5 + i7 + i9 + i11) + i2 + i4 + i6 + i8 + i10;
    
    if (9 - (total - 1) % 10 == i12)
        printf("UPC is valid\n");
    else printf("UPC isn't valid\n");
    
    return 0;
}
