#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

#define DAYS 7 
#define HOURS 24

void array_init(int rows, int cols, int a[rows] [cols]);
int *find_largest (int a[], int n);

int main(void)
{
    int day, temperature [DAYS] [HOURS];

    array_init(DAYS, HOURS, temperature);

    printf("The highest temperatures: ");
    for (int day = 0; day < DAYS; day++)
        printf("%d, ", *find_largest(temperature[day], HOURS));
    printf("\n");

    return 0;
}

void array_init(int rows, int cols, int a[rows] [cols])
{
    srand((unsigned) time(NULL));

    for (int i = 0, min = 20; i < rows; i++, min++) {
        for (int j = 0; j < cols; j++)
            a[i] [j] = min + rand() % 10;
    }
}

int *find_largest (int a[], int n)
{
    int *m = a;

    for (int *p = a + 1; p < a + n; p++)
        if (*p > *m)
            m = p;

    return m;
}
