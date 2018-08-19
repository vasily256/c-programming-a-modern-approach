#include <stdio.h> 

#define DOUBLE(x) 2*x
#define DOUBLE_FIXED(x) (2*x)

int main(void)
{
    int n = 2;

    //printf("Enter a number: ");
    //scanf("%d", &n);

    printf("(a) DOUBLE(1+2) by original definition: %d\n", DOUBLE(n));
    printf("(b) DOUBLE(1+2) by fixed definition: %d\n", DOUBLE_FIXED(n));

    return 0;
}
