int b, c;

void f(void)
{
    int b, d;
}

void g(int a)
{
    int c;
    {               // block
        int a, d;   //
    }               //
}

int main(void)
{
    int c, d;
}

/*      scope                visible parameters
                             and variables

   (a)  f function           b(f), c, d(f)
   (b)  g function           a(g), b, c(g)
   (c)  block                b, c(f), a(block), d(block)
   (d)  main function        b, c(main), d(main)
