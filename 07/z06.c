//See page 151

#include <stdio.h>

int main(void)
{
    printf("Size of _Bool int: %d\n", sizeof(_Bool));
    printf("Size of char int: %d\n", sizeof(char));
    printf("Size of short int: %d\n", sizeof(short));
    printf("Size of int: %d\n", sizeof(int));
    printf("Size of long int: %d\n", sizeof(long));
    printf("Size of long long int: %d\n", sizeof(long long));
    printf("Size of float: %d\n", sizeof(float));
    printf("Size of double: %d\n", sizeof(double));
    printf("Size of long double: %d\n", sizeof(long double));
    
    return 0;
}
