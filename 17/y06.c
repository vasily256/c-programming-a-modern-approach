#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

// Finds and deletes node in linked list
struct node *delete_from_list(struct node *list, int n)
{
    struct node *ptr = list, *tmp_ptr;

    if (list->value == n) {
        list = list->next;
        free(ptr);
        return list;
    }

    for (; ptr->next != NULL && ptr->next->value != n;
            ptr = ptr->next)
        ;

    if (ptr->next == NULL)
        return list;

    tmp_ptr = ptr->next->next;
    free(ptr->next);
    ptr->next = tmp_ptr;

    return list;
}

int main(void)
{
    int n;
    struct node *list, *n1, *n2, *n3, *n4;

    n4 = malloc(sizeof(struct node)); n4->value = 9; n4->next = NULL;
    n3 = malloc(sizeof(struct node)); n3->value = 3; n3->next = n4;
    n2 = malloc(sizeof(struct node)); n2->value = 2; n2->next = n3;
    list = n1 = malloc(sizeof(struct node)); n1->value = 5; n1->next = n2;

    printf("Initial values in linked list: ");
    for (struct node *ptr = list; ptr != NULL; ptr = ptr->next)
        printf("%d ", ptr->value);
    printf("\n");

    printf("Enter value to be deleted: ");
    scanf("%d", &n);
    list = delete_from_list(list, n);

    printf("Current values in linked list: ");
    for (struct node *ptr = list; ptr != NULL; ptr = ptr->next)
        printf("%d ", ptr->value);
    printf("\n");

    return 0;
}
