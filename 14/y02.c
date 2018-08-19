#include <stdio.h> 

#define NELEMS(a) ((int) (sizeof(a) / sizeof(a[0])))

int main(void)
{
    int n;

    printf("Enter number of array elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Number of array elements: %d\n", NELEMS(a));

    return 0;
}
