#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define N 5

float compute_GPA(char grades[], int n);

int main(void)
{
    int i, n = 5;
    char grades[n];
   
    printf("Enter %d letters: ", n);
    for (i = 0; i < n; i++)
        scanf(" %c", &grades[i]);

    printf("The average grade is: %g\n", compute_GPA(grades, n));
}

float compute_GPA(char grades[], int n)
{
    int sum = 0, i;
    char ch;
    
    for (i = 0; i < n; i++) {
        switch(toupper(grades[i])) {
            case 'A': sum += 4; break;
            case 'B': sum += 3; break;
            case 'C': sum += 2; break;
            case 'D': sum += 1; break;
            case 'F': break;
            default: printf("Illegal character\n"); exit(EXIT_SUCCESS);
        }
    }
    
    return (float) sum / n;
}
