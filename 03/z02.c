#include <stdio.h>

int main(void)
{
    int num, mm, dd, yyyy;
    float price;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("Enter unit price: ");
    scanf("%f", &price);
    
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &mm, &dd, &yyyy);
    
    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
    printf("%-8d\t$%7.2f\t%.2d/%.2d/%d\n", num, price, mm, dd, yyyy);
    
    return 0;
}
