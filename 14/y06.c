#include <stdio.h> 

#define DISP(f,x) printf(#f "(%g) = %g\n", x, f(x))
#define DISP2(f,x,y) printf(#f "(%g, %g) = %g\n", x, y, f(x, y))

int main(void)
{

    return 0;
}
