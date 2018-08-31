#include <stdio.h>

struct Date {
    int month;
    int day;
    int year;
};

int day_of_year(struct Date date);
int compare_dates(struct Date date1, struct Date date2);

int main(void)
{
    struct Date date1, date2;

    printf("Enter a date 1 (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &date1.month, &date1.day, &date1.year); 
    printf("Number of days: %d\n", day_of_year(date1));

    printf("Enter a date 2 (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &date2.month, &date2.day, &date2.year);
    printf("Number of days: %d\n", day_of_year(date2));

    printf("Date 1 ");
    switch (compare_dates(date1, date2)) {
        case -1:
            printf("<");
            break;
        case 0:
            printf("=");
            break;
        case 1:
            printf(">");
            break;
    }
    printf(" Date 2\n");

    return 0;
}

// (a) Returns number of days between Jan. 1 and given date
int day_of_year(struct Date date)
{
    const int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum_of_days = date.day;

    for (int i = 1; i < date.month; i++)
        sum_of_days += days_in_month[i-1];

    if (date.month > 2) {
        if (date.year % 400 == 0)
            sum_of_days++;
        else if (date.year % 100 != 0)
            if (date.year % 4 == 0)
                sum_of_days++;
    }

    return sum_of_days;
}

// (b) Compares two dates
int compare_dates(struct Date date1, struct Date date2)
{
    if (date1.year > date2.year)
        return 1;
    else if (date1.year < date2.year)
        return -1;
    else
        if (date1.month > date2.month)
            return 1;
        else if (date1.month < date2.month)
            return -1;
        else
            if (date1.day > date2.day)
                return 1;
            else if (date1.day < date2.day)
                return -1;
            else
                return 0;
}
