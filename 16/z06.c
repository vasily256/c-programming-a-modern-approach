#include <stdio.h>

struct Date {
    int month;
    int day;
    int year;
}; 

int compare_dates(struct Date date1, struct Date date2);

int main(void)
{
    struct Date date1, date2;
    
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &date1.month, &date1.day, &date1.year);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &date2.month, &date2.day, &date2.year);

    printf("First date ");
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
    printf(" Second date\n");
    
    return 0;
}

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
