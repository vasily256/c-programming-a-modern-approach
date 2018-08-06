/*
int a[N], *p = a;

(a) p == a[0]       illegal
(b) p == &a[0]      true
(c) *p == a[0]      true
(d) p[0] == a[0]    true
*/

#include <stdio.h>

int a[2], *p = a;

int main(void)
{
    printf("(a) illegal\n");
    printf("(b) %d\n", p == &a[0]);
    printf("(c) %d\n", *p == a[0]);
    printf("(d) %d\n", p[0] == a[0]); 
    
    return 0;
}
