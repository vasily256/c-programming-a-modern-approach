#include <stdio.h>
#define N 10

void quicksort(int *low, int *high);
int *split(int *low, int *high);

int main(void)
{
    int a[N], *p;

    printf("Enter %d numbers to be sorted: ", N);
    for (p = a; p < a + N; p++) {
        scanf("%d", p);
    }
    
    quicksort(&a[0], &a[N-1]);

    printf("In sorted order: ");
    for (p = a; p < a + N; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    return 0;
}

void quicksort(int *low, int *high)
{
    int *middle;
    
    if (low >= high) {
        return;
    }

    middle = split(low, high);
    quicksort(low, middle - 1);
    quicksort(middle + 1, high);
}

int *split(int *low, int *high)
{
    int temp = *low;

    for (;;) {
        while (high > low && *high >= temp) {
            high--;
        }
        if (low >= high) {
            break;
        }
        *low++ = *high;

        while (high > low && *low <= temp) {
            low++;
        }
        if (low >= high) {
            break;
        }
        *high-- = *low;
    }

    *high = temp;

    return high;
} 
