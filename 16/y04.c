#include <stdio.h>

// (a)
typedef struct {
    double real;
    double imaginary;
} Complex;

// (c)
Complex make_complex(double real, double imaginary);

// (d)
Complex add_complex(Complex c1, Complex c2);

int main(void)
{
    // (b)
    Complex c1, c2 = {0.1, 4.3}, c3;
    double real = 4.9, imaginary = 0.7;

    // (c)
    c1 = make_complex(real, imaginary);
    printf("Real: %g, imaginary: %g, complex: %g + %gi\n",
            real, imaginary, c1.real, c1.imaginary);

    // (d)
    c3 = add_complex(c1, c2);
    printf("(%g + %gi) + (%g + %gi) = %g + %gi\n",
           c1.real, c1.real, c2.real, c2.real, c3.real, c3.real);

    return 0;
}

// (c)
Complex make_complex(double real, double imaginary)
{
    Complex c;

    c.real = real;
    c.imaginary = imaginary;

    return c;
}

// (d)
Complex add_complex(Complex c1, Complex c2)
{
    Complex c;

    c.real = c1.real + c2.real;
    c.imaginary = c1.imaginary + c2.imaginary;

    return c;
}
