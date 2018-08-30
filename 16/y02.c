#include <stdio.h>

int main(void)
{
    // (a)
    // struct {
    //     double real;
    //     double imaginary;
    // } c1, c2, c3;

    // (b)
    struct {
        double real;
        double imaginary;
    } c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;

    printf("(b): c1 = {%.1f, %.1f}, c2 = {%.1f, %.1f}, c3 = {%.1f, %.1f}\n",
            c1.real, c1.imaginary, c2.real, c2.imaginary, c3.real, c3.imaginary); 

    // (c)
    c1 = c2;

    printf("(c): c1 = {%.1f, %.1f}, c2 = {%.1f, %.1f}, c3 = {%.1f, %.1f}\n",
            c1.real, c1.imaginary, c2.real, c2.imaginary, c3.real, c3.imaginary); 

    // (d)
    c3.real = c2.real + c1.real;
    c3.imaginary = c2.imaginary + c1.imaginary;

    printf("(d): c1 = {%.1f, %.1f}, c2 = {%.1f, %.1f}, c3 = {%.1f, %.1f}\n",
            c1.real, c1.imaginary, c2.real, c2.imaginary, c3.real, c3.imaginary); 

    return 0;
}
