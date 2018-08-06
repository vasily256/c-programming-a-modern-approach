#include <stdio.h>

int main(void)
{
    int n;
    const char *to_twenty[] = {"", "-one", "-two", "-three",
        "-four", "-five", "-six", "-seven", "-eight", "-nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const char *dec[] = {[2] = "twenty", "thirty", "forty",
        "fifty", "sixty", "seventy", "eighty", "ninety"};
    
    printf("Enter a two-digit number: ");
    scanf("%d", &n);

    if (n < 10 || n > 99) {
        printf("Error. The number isn't two-digit.\n");
        return 0;
    }

    printf("You entered the number: "); 

    if (n < 20)
        printf("%s\n", to_twenty[n]);
    else
        printf("%s%s\n", dec[n / 10], to_twenty[n % 10]);
    
    return 0;
}
