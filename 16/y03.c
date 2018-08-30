#include <stdio.h>

// (a)
struct complex {
    double real;
    double imaginary;
};

// (c)
struct complex make_complex(double real, double imaginary);

// (d)
struct complex add_complex(struct complex c1, struct complex c2);

int main(void)
{
    // (b)
    struct complex c1, c2 = {0.1, 4.3}, c3;
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
struct complex make_complex(double real, double imaginary)
{
    struct complex c;

    c.real = real;
    c.imaginary = imaginary;

    return c;
}

// (d)
struct complex add_complex(struct complex c1, struct complex c2)
{
    struct complex c;

    c.real = c1.real + c2.real;
    c.imaginary = c1.imaginary + c2.imaginary;

    return c;
}
