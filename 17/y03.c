#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value)
{
    int *a = malloc(n * sizeof(*a));

    if (a != NULL) {
        for (int i = 0; i < n; i++)
            a[i] = initial_value;
        return a;
    } else
        return NULL;
}

int main(void)
{
    int *a, n, initial_value;

    printf("Enter array length and initial value: ");
    scanf("%d %d", &n, &initial_value);

    a = create_array(n, initial_value);

    if (a == NULL) {
        printf("malloc: allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
