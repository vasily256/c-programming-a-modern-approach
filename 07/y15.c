#include <stdint.h>
#include <stdio.h>

int main(void)
{
    typedef int8_t int8;
    typedef int16_t int16;
    typedef int32_t int32;
    typedef int64_t int64;
    
    printf("int8: %d, int16: %d, int32: %d, int64: %d\n", sizeof(int8), sizeof(int16), sizeof(int32), sizeof(int64));
    
    return 0;
}
