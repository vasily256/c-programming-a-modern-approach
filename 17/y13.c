#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

/* Original version
struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
{
    struct node *cur = list, *prev = NULL;
    while (cur->value <= new_node->value) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = new_node;
    new_node->next = cur;
    return list;
} */

// Fixed version
struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
{
    struct node *cur = list, *prev = NULL;

    while (cur != NULL && cur->value <= new_node->value) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL)
        list = new_node;
    else
        prev->next = new_node;

    new_node->next = cur; 
    return list;
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

struct node *create_node(int n)
{
    struct node *new_node = malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("malloc: allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = n;

    return new_node;
}

int main(void)
{
    int n;
    struct node *list = linked_list_init(), *new_node;

    printf("Initial values in linked list: ");
    print_list(list);

    printf("Enter value to be inserted: ");
    scanf("%d", &n);
    new_node = create_node(n);
    list = insert_into_ordered_list(list, new_node);

    printf("Current values in linked list: ");
    print_list(list);

    return 0;
} 
