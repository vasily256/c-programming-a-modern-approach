#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

int count_occurences(struct node *list, int n)
{
    int count = 0;

    for (; list != NULL; list = list->next)
        if (list->value == n)
            ++count;

    return count;
}

int main(void)
{
    int n, count;
    struct node *list, *n1, *n2, *n3, *n4, *ptr;

    n4 = malloc(sizeof(struct node)); n4->value = 5; n4->next = NULL;
    n3 = malloc(sizeof(struct node)); n3->value = 5; n3->next = n4;
    n2 = malloc(sizeof(struct node)); n2->value = 2; n2->next = n3;
    list = n1 = malloc(sizeof(struct node)); n1->value = 5; n1->next = n2;

    printf("Initial values in linked list: ");
    for (ptr = list; ptr != NULL; ptr = ptr->next)
        printf("%d ", ptr->value);
    printf("\n");

    printf("Enter a value: ");
    scanf("%d", &n);
    count = count_occurences(list, n);

    printf("Number of occurences in linked list: %d\n", count);

    return 0;
}
