#include <stdio.h>

#define R 2 
#define C 4

int main(void)
{
    char a[R] [C], (*p) [C];

    printf("Rows: %d, columns: %d\n", R, C);
    printf( "*a:\t\t%d\n"
            "*(&a):\t\t%d\n"
            "*a[0]:\t\t%d\n"
            "*(a[0]):\t%d\n"
            "*(&a[0]):\t%d\n" 
            "*(&(a[0])):\t%d\n"
            "a[0] [0]:\t%d\n"
            "*(&a[0] [0]):\t%d\n"
            "*p:\t\t%d\n"
            "(*p) [0]:\t%d\n",
            sizeof(     *a              ),
            sizeof(     *(&a)           ),
            sizeof(     *a[0]           ),
            sizeof(     *(a[0])         ),
            sizeof(     *(&a[0])        ),
            sizeof(     *(&(a[0]))      ),
            sizeof(     a[0] [0]        ),
            sizeof(     *(&a[0] [0])    ),
            sizeof(     *p              ),
            sizeof(     (*p) [0]        )
            );

    return 0;
}
