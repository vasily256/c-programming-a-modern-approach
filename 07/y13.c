#include <stdio.h>

int main(void)
{
    char c = '\1';
    short s = 2;
    int i = -3;
    long m = 5;
    float f = 6.5f;
    double d = 7.5;
    
    printf("%d\n", c * i);    // int -3
    printf("%ld\n", s + m);   // long 7
    printf("%g\n", f / c);    // float 6.5
    printf("%g\n", d / s);    // double 3.75
    printf("%g\n", f - d);    // double -1
    printf("%d\n", (int) f);  // int 6
}
