#include <stdio.h>

#define N 5

void find_two_largest(const int *a, int n, int *largest,
                      int *second_largest);

int main(void)
{
    int a[N], i, biggest, big;

    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    find_two_largest(a, N, &biggest, &big);

    printf("Largest: %d\n", biggest);
    printf("Second largest: %d\n", big);
}

void find_two_largest(const int *a, int n, int *largest,
                      int *second_largest)
{
    const int *max1, *max2, *ptr; 

    max1 = max2 = a;
    for (ptr = a + 1; ptr < a + n; ptr++) {
        if (*ptr > *max1) {
            max2 = max1;
            max1 = ptr;
        } else if (*ptr > *max2) { 
            max2 = ptr;
        } else if (*max2 == *max1) { 
            max2 = ptr;
        }
    }

    *largest = *max1;
    *second_largest = *max2;
}
