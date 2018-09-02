#include <stdio.h>

int main(void)
{
    // (a)
    enum      {NUL, SOH, STX, ETX};
    // value:  0    1    2    3  

    // (b)
    enum      {VT = 11, FF, CR};
    // value:  11       12  13  
    printf("%d %d\n", FF, CR);

    // (c)
    enum      {SO = 14, SI, DLE, CAN = 24, EM};
    // value:  14       15  16   24        25 
    printf("%d %d %d %d\n", SI, DLE, CAN, EM);

    // (c)
    enum       {ENQ = 45, ACK, BEL, LF = 37, ETB, ESC};
    // value:   45        46   47   37       38   39 
    printf("%d %d %d %d %d\n", ACK, BEL, LF, ETB, ESC);

    return 0;
}
