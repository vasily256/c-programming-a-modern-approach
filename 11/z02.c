#include <stdio.h>

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

void find_closest_flight(int desired_time, int *departure_time,
        int *arrival_time);

int main(void)
{
    int hours, minutes, desired_time, departure_time, arrival_time;
    
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);
    
    desired_time = 60 * hours + minutes; 
    find_closest_flight(desired_time, &departure_time, &arrival_time);

    printf("Closest departure time is %.2d:%.2d, ", departure_time / 60, departure_time % 60);
    printf("arriving at %.2d:%.2d\n", arrival_time / 60, arrival_time % 60);
}

void find_closest_flight(int desired_time, int *departure_time,
        int *arrival_time)
{
    if (desired_time - D0 < D1 - desired_time) {
        *departure_time = D0;
        *arrival_time = A0;
    } else if (desired_time - D1 < D2 - desired_time) {
        *departure_time = D1;
        *arrival_time = A1;
    } else if (desired_time - D2 < D3 - desired_time) {
        *departure_time = D2;
        *arrival_time = A2;
    } else if (desired_time - D3 < D4 - desired_time) {
        *departure_time = D3;
        *arrival_time = A3;
    } else if (desired_time - D4 < D5 - desired_time) {
        *departure_time = D5;
        *arrival_time = A5;
    } else if (desired_time - D5 < D6 - desired_time) {
        *departure_time = D5;
        *arrival_time = A5;
    } else if (desired_time - D6 < D7 - desired_time) {
        *departure_time = D6;
        *arrival_time = A6;
    } else {
        *departure_time = D7;
        *arrival_time = A7;
    }
}
