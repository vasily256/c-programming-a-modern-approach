/***************************************************************
    (a) int (*f(float (*)(long), char *))(double);
    f is a function with two arguments: pointer to
    function with long integer argument and float return value,
    pointer to character. Function f returns pointer to function
    that has double argumemt and integer return value.

    (b) i = (*(f(g, c)))(x);
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

long n;

int (*f(float (*g)(long n), char *cmd))(double x);
float g(long);
int h_a(double x);
int h_b(double x);

int main(void)
{
    char cmd;
    double x;

    printf("Enter a value n: ");
    scanf("%ld", &n);

    printf("Enter a value x: ");
    scanf("%lf", &x);

    printf("Enter a command :");
    scanf(" %c", &cmd);

    printf("Result: %d\n", (*(f(g, &cmd)))(x));

    return 0;
}

float g(long n)
{
    float x = n;
    return x / 1000.0f;
}

int (*f(float (*g)(long n), char *cmd))(double x)
{
    float x = (*g)(n);

    switch (*cmd) {
        case 'a':
            return h_a;
        case 'b':
            return h_b;
        default:
            exit(EXIT_SUCCESS);
    }
}

int h_a(double x)
{
    return (int) x - (int) n;
}

int h_b(double x)
{
    return (int) x + (int) n;
}
