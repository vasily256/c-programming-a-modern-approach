#include <stdio.h> 

#define unsigned_long unsigned long 
#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
    return x > y ? x : y;       \
}

GENERIC_MAX(long) 
GENERIC_MAX(unsigned_long)

int main(void)
{
    long a, b;
    unsigned long c, d;

    printf("Enter a and b 'long' values: ");
    scanf("%ld %ld", &a, &b);
    printf("Maximal value: %ld\n", long_max(a, b));

    printf("Enter c and d 'unsigned long' values: ");
    scanf("%lu %lu", &a, &b);
    printf("Maximal value: %ld\n", unsigned_long_max(a, b));

    return 0;
}
