#include <stdio.h>
#define N 10

void qsort(int a[], int low, int high);
int split(int a[], int low, int high);

int main(void)
{
    int a[N], i;

    printf("Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    
    qsort(a, 0, N - 1);

    printf("In sorted order: ");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void qsort(int a[], int low, int high)
{
    int middle;
    
    if (low >= high) {
        return;
    }

    middle = split(a, low, high);
    qsort(a, low, middle - 1);
    qsort(a, middle + 1, high);
}

int split(int a[], int low, int high)
{
    int temp = a[low];

    for (;;) {
        while (high > low && a[high] >= temp) {
            high--;
        }
        if (low >= high) {
            break;
        }
        a[low++] = a[high];

        while (high > low && a[low] <= temp) {
            low++;
        }
        if (low >= high) {
            break;
        }
        a[high--] = a[low];
    }

    a[high] = temp;
    return high;
}






