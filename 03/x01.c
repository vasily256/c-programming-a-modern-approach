#include <stdio.h>

int main(void)
{
    printf("%6d,%4d\n", 86, 1040);      //"    86,1040"
    printf("%12.5e\n", 30.253);         //" 3.02530e+01"
    printf("%.4f\n", 30.253);           //"30.2530"
    printf("%-6.2g\n", .0000009979);    //"1e-06"
    
    return 0;
}
