#include <stdio.h>

struct fraction {
    int numer;
    int denom;
};

struct fraction reduce(struct fraction f);

// Adds (b), substracts (c), multiplies (d), divides (e) two fractions

int main(void)
{
    struct fraction f1, f2, f3;
    char ch;
    
    printf("Enter two fractions separated by +, -, *, or /:\n");
    scanf("%d/%d %c %d/%d", &f1.numer, &f1.denom, &ch, &f2.numer, &f2.denom);
    
    switch (ch) {
        case '+':
            f3.numer = f1.numer * f2.denom + f2.numer * f1.denom;
            f3.denom = f1.denom * f2.denom;
            break;
        case '-':
            f3.numer = f1.numer * f2.denom - f2.numer * f1.denom;
            f3.denom = f1.denom * f2.denom;
            break;
        case '*':
            f3.numer = f1.numer * f2.numer;
            f3.denom = f1.denom * f2.denom;
            break;
        case '/':
            f3.numer = f1.numer * f2.denom;
            f3.denom = f1.denom * f2.numer;
            break;
    } 
    f3 = reduce(f3);

    printf("= %d/%d\n", f3.numer, f3.denom);
    
    return 0;
}

// (a) Reduces fraction to lowest terms

struct fraction reduce(struct fraction f)
{ 
    int r, n = f.numer, d = f.denom;

    while (d != 0) {
        r = n % d;
        n = d;
        d = r;
    }
    
    f.numer /= n;
    f.denom /= n;

    return f;
}
