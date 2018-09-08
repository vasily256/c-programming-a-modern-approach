/* Initial version
for (p = first; p != NULL; p = p->next)
    free(p);
*/

/* Fixed version
for (p = first; p != NULL; ) {
    t = p;
    p = p->next;
    free(t);
}
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    struct node {
        int value;
        struct node *next;
    } *list, *n1, *n2, *n3, *n4;

    n4 = malloc(sizeof(struct node)); n4->value = 9; n4->next = NULL;
    n3 = malloc(sizeof(struct node)); n3->value = 3; n3->next = n4;
    n2 = malloc(sizeof(struct node)); n2->value = 2; n2->next = n3;
    list = n1 = malloc(sizeof(struct node)); n1->value = 5; n1->next = n2;

    printf("Initial linked list: ");
    for (struct node *ptr = list; ptr != NULL; ptr = ptr->next)
        printf("%d ", ptr->value);
    printf("\n");

    // Clears linked list
    struct node *p, *t; 
    for (p = list; p != NULL; ) {
        t = p;
        p = p->next;
        free(t);
    }

    printf("Cleared linked list: ");
    for (struct node *ptr = list; ptr != NULL; ptr = ptr->next)
        printf("%d ", ptr->value);
    printf("\n");

    return 0;
}
