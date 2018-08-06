#include <stdio.h>
#define N 5

int main(void)
{
    int c[N] = {0}, r[N] = {0};
    int i, j, n;
    
    for (i = 0; i < N; i++) {
        printf("Enter row %d: ", i + 1);
        for (j = 0; j < N; j++) {
            scanf("%d", &n);
            c[j] += n;
            r[i] += n;
        }
    }
    
    printf("Row totals:");
    for (i = 0; i < N; i++) {
        printf(" %d", r[i]);
    }
    printf("\n");
    
    printf("Column totals:");
    for (j = 0; j < N; j++) {
        printf(" %d", c[j]);
    }
    printf("\n");
    
    return 0;
}
