int a;

void f(int b)
{
    int c;
}

void g(void)
{
    int d;
    {               // block
        int e;      //
    }               //
}

int main(void)
{
    int f;
}

/*      scope               visible parameters
                            and variables

   (a)  f function           a, b, c
   (b)  g function           a, d
   (c)  block                a, d, e
   (d)  main function        a, f
