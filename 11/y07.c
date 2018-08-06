#include <stdio.h>

void split_date(int day_of_year, int year, int *month, int *day);

int main(void)
{
    int day_of_year, year, month, day;

    printf("Enter the year: ");
    scanf("%d", &year);

    printf("Enter number of days: ");
    scanf("%d", &day_of_year);

    split_date(day_of_year, year, &month, &day);

    printf("Date: %.2d.%.2d.%d\n", day, month, year);

    return 0;
}

void split_date(int day_of_year, int year, int *month, int *day)
{
    int i;
    int days_in_month[12] = {31, 28, 31, 30, 31, 30,
                             31, 31, 30, 31, 30, 31};

    // Учет високосного года
    if (year % 400 == 0)
        days_in_month[1]++;
    else if (year % 100 != 0)
        if (year % 4 == 0)
            days_in_month[1]++;

    *day = day_of_year;
    for (i = 0; days_in_month[i] < *day; i++)
        *day -= days_in_month[i];
    *month = ++i;
}
