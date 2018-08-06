#include <stdio.h>

#define NUM_ROWS 5 
#define NUM_COLS 5

void array_init(int rows, int cols, int a[rows] [cols]);
void row_write_2d(int r, int cols, int a[] [cols]);
void row_write_1d(int cols, int a[]);
void col_write(int c, int rows, int cols, int a[rows] [cols]);
void col_write2(int c, int rows, int cols, int a[rows] [cols]);
void col_write3(int c, int rows, int cols, int a[rows] [cols]);
void array_print(int rows, int cols, int a[rows] [cols]);

int main(void)
{
    int i, a[NUM_ROWS] [NUM_COLS];

    array_init(NUM_ROWS, NUM_COLS, a);
    array_print(NUM_ROWS, NUM_COLS, a);
    
    row_write_2d(1, NUM_COLS, a); // Write whole 2nd row
    array_print(NUM_ROWS, NUM_COLS, a);

    row_write_1d(NUM_COLS, a[3]); // Write whole 4th row
    array_print(NUM_ROWS, NUM_COLS, a);

    col_write(2, NUM_ROWS, NUM_COLS, a); // Write whole 3th column
    array_print(NUM_ROWS, NUM_COLS, a);

    col_write2(4, NUM_ROWS, NUM_COLS, a); // Write whole 5th column
    array_print(NUM_ROWS, NUM_COLS, a);

    col_write3(3, NUM_ROWS, NUM_COLS, a); // Write whole 4th column
    array_print(NUM_ROWS, NUM_COLS, a);

    return 0;
}

void array_init(int rows, int cols, int a[rows] [cols])
{
    for (int *p = a[0]; p <= &a[rows-1] [cols-1]; p++) {
        *p = 0;
    }
}

void row_write_2d(int r, int cols, int a[] [cols])
{
    for (int *p = a[r]; p < a[r] + cols; p++) {
        *p = 2;
    }
}

void row_write_1d(int cols, int a[])
{
    for (int i = 0; i < cols; i++) {
        a[i] = 1;
    }
}

void col_write(int c, int rows, int cols, int a[rows] [cols])
{
    for (int (*p) [cols] = a; p < a + rows; p++) {
        (*p) [c] = 3;
    }
}

void col_write2(int c, int rows, int cols, int a[rows] [cols])
{
    for (int (*p) [cols] = &a[0]; p < &a[rows]; p++) {
        (*p) [c] = 4;
    }
}

void col_write3(int c, int rows, int cols, int a[rows] [cols])
{
    for (int r = 0; r < rows; r++) {
        a[r] [c] = 5;
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
