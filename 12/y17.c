#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HGT 5
#define LEN 5

void array_init(int rows, int cols, int a[rows] [cols]);
void array_print(int rows, int cols, int a[rows] [cols]);
int sum_two_dimensional_array(const int a[] [LEN], int n);
int sum_two_dimensional_array_2(const int *a, int n);

int main(void)
{
    int i, a[HGT] [LEN];

    array_init(HGT, LEN, a);
    array_print(HGT, LEN, a);

    printf("Sum (based on array subscripting): %d\n",
            sum_two_dimensional_array(a, HGT));
    printf("\n");

    printf("Sum (based on pointer arithmetic): %d\n",
            sum_two_dimensional_array_2(a[0], HGT * LEN));
    printf("\n");

    return 0;
}

//  Sum (based on array subscripting)

int sum_two_dimensional_array(const int a[] [LEN], int n)
{
    int i, j, sum = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < LEN; j++)
            sum += a[i] [j];

    return sum;
}
//  Sum (based on pointer arithmetic)

int sum_two_dimensional_array_2(const int *a, int n)
{
    const int *p;
    int sum = 0;

    for (p = a; p < a + n; p++)
        sum += *p;

    return sum;
}

void array_init(int rows, int cols, int a[rows] [cols])
{
    srand((unsigned) time(NULL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            a[i] [j] = rand() % 10;
    }
}

void array_print(int rows, int cols, int a[rows] [cols])
{
    for (int *p = a[0]; p <= &a[rows-1] [cols-1]; p++) {
        printf(" %d", *p);
        if ((p - a[0]) % cols == cols - 1) {
            printf("\n");
        }
    }
    printf("\n");
}
