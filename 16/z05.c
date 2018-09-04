#include <stdio.h>

#define LEN ((int) (sizeof(flights) / sizeof(flights[0])))

#define D0 (60 * 8 + 0)
#define D1 (60 * 9 + 43)
#define D2 (60 * 11 + 19)
#define D3 (60 * 12 + 47)
#define D4 (60 * 14 + 0)
#define D5 (60 * 15 + 45)
#define D6 (60 * 19 + 0)
#define D7 (60 * 21 + 45)
#define A0 (60 * 10 + 16)
#define A1 (60 * 11 + 52)
#define A2 (60 * 13 + 31)
#define A3 (60 * 15)
#define A4 (60 * 16 + 8)
#define A5 (60 * 17 + 55)
#define A6 (60 * 21 + 20)
#define A7 (60 * 23 + 58)

int main(void)
{
    int h, m, t, i;
    struct flight {int dep, arr;} flights[] = {
        {D0, A0}, {D1, A1}, {D2, A2}, {D3, A3},
        {D4, A4}, {D5, A5}, {D6, A6}, {D7, A7}
    };

    
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &h, &m);
    
    t = 60 * h + m;
    
    printf("Closest departure time is ");
    
    for (i = 0; i < LEN - 1; i++) {
        if (t - flights[i].dep < flights[i+1].dep - t) {
            break;
        }
    }
    
    printf("%.2d:%.2d, arriving at %.2d:%.2d p.m.\n", flights[i].dep / 60,
            flights[i].dep % 60, flights[i].arr / 60, flights[i].arr % 60);
    
    return 0;
}
