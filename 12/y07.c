#include <stdbool.h>
#include <stdio.h>

#define N 5

bool search(const int a[], int n, int key);

int main(void)
{ 
    int a[N], key;

    printf("Enter a key: ");
    scanf("%d", &key);

    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    if (search(a, N, key))
        printf("Key matches\n");
    else 
        printf("Key doesn't match\n");
}

bool search(const int a[], int n, int key)
{
    for (const int *p = a; p < a + n; p++)
        if (*p == key)
            return true;
    return false;
}
