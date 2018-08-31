#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time split_time(long total_seconds);

int main(void)
{
    long total_seconds;
    struct Time time;

    printf("Enter number of seconds since midnight: ");
    scanf("%ld", &total_seconds);

    time = split_time(total_seconds);

    printf("The time is: %.2d:%.2d:%.2d\n", time.hours, time.minutes, time.seconds);

    return 0;
}

// Returns a structure containing the equivalent time in hours, minutes and seconds
struct Time split_time(long total_seconds)
{
    struct Time time;

    time.hours = total_seconds / 3600;
    total_seconds = total_seconds % 3600; 
    time.minutes = total_seconds / 60;
    time.seconds = total_seconds % 60;

    return time;
}
