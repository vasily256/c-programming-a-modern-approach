#include <stdio.h>
#include <ctype.h>

#define D0 (60 * 8 + 0)
#define D1 (60 * 9 + 43)
#define D2 (60 * 11 + 19)
#define D3 (60 * 12 + 47)
#define D4 (60 * 14 + 0)
#define D5 (60 * 15 + 45)
#define D6 (60 * 19 + 0)
#define D7 (60 * 21 + 45)

int main(void)
{
    int h, m, t;
    char ch;
    
    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c", &h, &m, &ch);
    
    ch = toupper(ch);
    switch (ch) {
        case 'A':
            h = h == 12 ? 0 : h;
            break;
        case 'P':
            h = h < 12 ? h + 12 : h;
            break;
    }
    
    t = 60 * h + m;
    
    printf("Closest departure time is ");
    
    if (t - D0 < D1 - t)
        printf("8:00 a.m., arriving at 10:16 a.m.\n");
    else if (t - D1 < D2 - t)
        printf("9:43 a.m., arriving at 11:52 a.m.\n");
    else if (t - D2 < D3 - t)
        printf("11:19 a.m., arriving at 1:31 p.m.\n");
    else if (t - D3 < D4 - t)
        printf("12:47 p.m., arriving at 3:00 p.m.\n");
    else if (t - D4 < D5 - t)
        printf("2:00 p.m., arriving at 4:08 p.m.\n");
    else if (t - D5 < D6 - t)
        printf("3:45 p.m., arriving at 5:55 p.m.\n");
    else if (t - D6 < D7 - t)
        printf("7:00 p.m., arriving at 9:20 p.m.\n");
    else
        printf("9:45 p.m., arriving at 11:58 p.m.\n");
}
