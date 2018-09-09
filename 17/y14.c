#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void delete_from_list(struct node **list, int n)
{
    struct node *cur, *prev;

    for (cur = *list, prev = NULL;
            cur != NULL && cur->value != n;
            prev = cur, cur = cur->next)
        ;

    if (cur == NULL)
        return;
    if (prev == NULL)
        *list = (*list)->next;
    else
        prev->next = cur->next;
    free(cur);
}

struct node *linked_list_init(void)
{ 
    struct node *n1, *n2, *n3, *n4;

    n4 = malloc(sizeof(struct node)); n4->value = 9; n4->next = NULL;
    n3 = malloc(sizeof(struct node)); n3->value = 8; n3->next = n4;
    n2 = malloc(sizeof(struct node)); n2->value = 6; n2->next = n3;
    n1 = malloc(sizeof(struct node)); n1->value = 3; n1->next = n2;

    return n1;
}

void print_list(struct node *list)
{ 
    for (; list != NULL; list = list->next)
        printf("%d ", list->value);
    printf("\n");
}

int main(void)
{
    int n;
    struct node *list = linked_list_init(), *new_node;

    printf("Initial values in linked list: ");
    print_list(list);

    printf("Enter value to be deleted: ");
    scanf("%d", &n);
    delete_from_list(&list, n);

    printf("Current values in linked list: ");
    print_list(list);

    return 0;
} 
