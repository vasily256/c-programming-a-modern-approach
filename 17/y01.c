#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t size)
{
    void *ptr = malloc(size);

    if (ptr == NULL) {
        printf("malloc: allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int main(void)
{
    double *a;
    long n;

    printf("Enter array length: ");
    scanf("%ld", &n);
    a = my_malloc(n * sizeof(*a));

    return 0;
}
