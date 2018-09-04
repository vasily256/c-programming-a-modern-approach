#include <stdio.h>
#define D ((int) (sizeof(dep) / sizeof(dep[0])))
#define A ((int) (sizeof(arr) / sizeof(arr[0])))

int main(void)
{
    int h, m, t, i;
    int dep[] = {60*8, 60*9+43, 60*11+19, 60*12+47, 60*14, 60*15+45, 60*19, 60*21+45};
    int arr[] = {60*10+16, 60*11+52, 13*60+31, 15*60, 60*16+8, 60*17+55, 60*21+20, 60*21+58};
    
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &h, &m);
    
    t = 60 * h + m;
    
    printf("Closest departure time is ");
    
    for (i = 0; i < D - 1; i++) {
        if (t - dep[i] < dep[i+1] - t) {
            break;
        }
    }
    
    printf("%.2d:%.2d, arriving at %.2d:%.2d p.m.\n", dep[i] / 60, dep[i] % 60, arr[i] / 60, arr[i] % 60);
    
    return 0;
}
