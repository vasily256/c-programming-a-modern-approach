#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void generate_random_walk(int r, int c, char walk[] [c]);
void print_array(int r, int c, char walk[] [c]);

int main(void)
{
    int r, c;
   
    printf("Enter numbers of rows and columns: ");
    scanf("%d%d", &r, &c);
    printf("\n");
    
    char walk[r] [c];
    
    generate_random_walk(r, c, walk);
    print_array(r, c, walk);
  
    return 0;
}

void generate_random_walk(int r, int c, char walk[] [c])
{
    int i, j, n;
    int k[4] = {0};
    char ch = '0';
 
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            walk[i] [j] = '.';
        }
    }
    
    srand((unsigned) time(NULL));
    
    i = rand() % r;
    j = rand() % c;
    walk[i] [j] = ch;
    while (ch < 'z') {
        n = rand() % 4;
        switch (n) {
            case 0:
                if (i > 0 && walk[i-1] [j] == '.') {
                    i--;
                    ch++;
                    walk[i] [j] = ch;
                    for (int m = 0; m < 4; m++) {
                        k[m] = 0;
                    }
                    break;
                } else {
                    k[n] = 1;
                    break;
                }
            case 1:
                if (j < c - 1 && walk[i] [j+1] == '.') {
                    j++;
                    ch++;
                    walk[i] [j] = ch;
                    for (int m = 0; m < 4; m++) {
                        k[m] = 0;
                    }
                    break;
                } else {
                    k[n] = 1;
                    break;
                }
            case 2:
                if (i < r - 1 && walk[i+1] [j] == '.') {
                    i++;
                    ch++;
                    walk[i] [j] = ch;
                    for (int m = 0; m < 4; m++) {
                        k[m] = 0;
                    }
                    break;
                } else {
                    k[n] = 1;
                    break;
                }
            case 3:
                if (j > 0 && walk[i] [j-1] == '.') {
                    j--;
                    ch++;
                    walk[i] [j] = ch;
                    for (int m = 0; m < 4; m++) {
                        k[m] = 0;
                    }
                    break;
                } else {
                    k[n] = 1;
                    break;
                }
        }
        if (k[0] + k[1] + k[2] + k[3] == 4) {
            break;
        }
        if (ch == 'Z') {
            ch = 'a' - 1;
        }
        if (ch == '9') {
            ch = 'A' - 1;
        }
    }
}

void print_array(int r, int c, char walk[] [c])
{
    int i, j;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%c ", walk[i] [j]);
        }
        printf("\n");
    }
    printf("\n");
} 
