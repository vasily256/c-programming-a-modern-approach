#include <stdio.h>

int main(void)
{
    int month, day, year;
    const char *months[] = {"January", "February", "March",
        "April", "May", "June", "July", "August", "September",
        "October", "November", "December"};

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%d", &month, &day, &year);

    printf("You entered date %s %d, %d\n", months[month - 1],
            day, year);

    return 0;
}
