#include <stdio.h>

int day_of_year(int month, int day, int year);

int main(void)
{
    int month, day, year;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);
    
    printf("Number of days: %d\n", day_of_year(month, day, year));
}

// Вычисление количества дней с начала года по дате
int day_of_year(int month, int day, int year)
{
    const int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum_of_days = day;

    for (int i = 1; i < month; i++)
        sum_of_days += days_in_month[i-1];

    // Учет високосного года
    if (month > 2)
        if (year % 400 == 0)
            sum_of_days++;
        else if (year % 100 != 0)
            if (year % 4 == 0)
                sum_of_days++;

    return sum_of_days;
}
