#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    int number;
    struct node *next;
};

struct node *find_last(struct node *list, int n)
{
    struct node *ptr = NULL;

    for (; list != NULL; list = list->next)
        if (list->value == n)
            ptr = list;

    return ptr;
}

int main(void)
{
    int n;
    struct node *list, *n1, *n2, *n3, *n4, *ptr;

    n4 = malloc(sizeof(struct node)); n4->value = 9; n4->number = 4; n4->next = NULL;
    n3 = malloc(sizeof(struct node)); n3->value = 3; n3->number = 3; n3->next = n4;
    n2 = malloc(sizeof(struct node)); n2->value = 2; n2->number = 2; n2->next = n3;
    list = n1 = malloc(sizeof(struct node)); n1->value = 3; n1->number = 1; n1->next = n2;

    printf("Initial values in linked list: ");
    for (ptr = list; ptr != NULL; ptr = ptr->next)
        printf("%d ", ptr->value);
    printf("\n");

    printf("Enter a value: ");
    scanf("%d", &n);
    ptr = find_last(list, n);

    if (ptr != NULL)
        printf("Number of last value in linked list: %d\n", ptr->number);
    else 
        printf("Number not found\n");

    return 0;
}
