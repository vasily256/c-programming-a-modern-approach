#include <stdio.h>

void reduce(int numerator, int denominator,
        int *reduced_numerator, int *reduced_denominator);

int main(void)
{
    int numerator, denominator;
    int reduced_numerator, reduced_denominator;

    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);

    reduce(numerator, denominator, &reduced_numerator,
            &reduced_denominator);

    printf("In lowest terms: %d/%d\n",
            reduced_numerator, reduced_denominator);
    
    return 0;
}

void reduce(int numerator, int denominator,
        int *reduced_numerator, int *reduced_denominator)
{ 
    int r, n = numerator, d = denominator;

    while (d != 0) {
        r = n % d;
        n = d;
        d = r;
    }
    
    *reduced_numerator = numerator / n;
    *reduced_denominator = denominator / n;
}
