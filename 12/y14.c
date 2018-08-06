#include <stdbool.h>
#include <stdio.h>

#define DAYS 7 
#define HOURS 24
#define KEY_TEMP 32

bool search(const int *a, int n, int key);

int main(void)
{
    int day, hour, temperature [DAYS] [HOURS] = {0};

    printf("Enter a day and a hour: ");
    scanf("%d %d", &day, &hour);
    if (day >= DAYS || hour >= HOURS) {
        printf("Error\n");
        return 0;
    }

    printf("Enter a value: ");
    scanf("%d", &temperature[day] [hour]);

    if (search(temperature[0], DAYS * HOURS, KEY_TEMP))
        printf("Key matches\n");
    else 
        printf("Key doesn't match\n");

    return 0;
}

bool search(const int *a, int n, int key)
{
    for (const int *p = a; p < a + n; p++)
        if (*p == key)
            return true;
    return false;
}
