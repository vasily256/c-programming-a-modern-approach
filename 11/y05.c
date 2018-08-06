#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec);

int main(void)
{
    long total_sec;
    int hours, minutes, seconds;

    printf("Enter number of seconds since midnight: ");
    scanf("%ld", &total_sec);

    split_time(total_sec, &hours, &minutes, &seconds);

    printf("The time is: %.2d:%.2d:%.2d\n", hours, minutes, seconds);

    return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec)
{
    *hr = total_sec / 3600;
    total_sec = total_sec % 3600; 
    *min = total_sec / 60;
    *sec = total_sec % 60;
}
