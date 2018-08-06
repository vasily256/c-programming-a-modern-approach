#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

#define DAYS 7 
#define HOURS 24

void array_init(int rows, int cols, int a[rows] [cols]);
void array_print(int cols, int *a);

int main(void)
{
    int day, temperature [DAYS] [HOURS];

    array_init(DAYS, HOURS, temperature);

    printf("Enter a day between 0 and %d: ", DAYS - 1);
    scanf("%d", &day);
    if (day >= DAYS) {
        printf("Error\n");
        return 0;
    }

    array_print(HOURS, temperature[day]);

    return 0;
}

void array_init(int rows, int cols, int a[rows] [cols])
{
    srand((unsigned) time(NULL));

    for (int i = 0, min = 20; i < rows; i++, min++) {
        for (int j = 0; j < cols; j++)
            a[i] [j] = min + rand() % 5;
    }
}

void array_print(int cols, int *a)
{
    for (int *p = a; p < a + cols; p++) {
        printf(" %d", *p);
    }
    printf("\n");
}
