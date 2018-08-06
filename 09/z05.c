#include <stdio.h>

void create_magic_square(short n, short magic_square[n] [n]);
void print_magic_square(short n, short magic_square[n] [n]);

int main(void)
{
    short n, i, j;
    
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%hd", &n);
    
    short m[n] [n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m[i] [j] = 0;
        }
    }
    
    create_magic_square(n, m);
    print_magic_square(n, m);
    
    return 0;
}

void create_magic_square(short n, short m[n] [n])
{
    short i, j, k;

    i = 0;
    j = n / 2;
    k = 1;
    while (k <= n * n) {
        m[i] [j] = k++;
        if (m[(i - 1 + n) % n] [(j + 1 + n) % n] == 0) {
            i = (--i + n) % n;
            j = (++j + n) % n;
        } else {
            i = (++i + n) % n;
        }
    }
}

void print_magic_square(short n, short m[n] [n])
{
    short i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%5hd", m[i] [j]);
        }
        putchar('\n');
    }
    putchar('\n');
}
