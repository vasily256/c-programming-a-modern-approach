#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "queueADT.h" 

struct node {
    Item data;
    struct node *next;
};

struct queue_type {
    struct node *first;
    struct node *last;
};

bool is_empty(Queue q)
{
    return q->first == NULL;
}

bool is_full(Queue q)
{
    return false;
}

Item remove_first(Queue q)
{
    assert(!is_empty(q));

    Item i = q->first->data;
    struct node *old_node = q->first;

    q->first = q->first->next;
    free(old_node);
    return i;
} 

void make_empty(Queue q)
{
    while(!is_empty(q))
        remove_first(q);
}

Queue create(void)
{
    Queue q = malloc(sizeof(struct queue_type));
    assert(q != NULL);

    q->first = q->last = NULL;
    return q;
}

void destroy(Queue q)
{
    make_empty(q);
    free(q);
}

void insert_last(Queue q, Item i)
{
    struct node *new_node = malloc(sizeof(struct node));
    assert(new_node != NULL);

    new_node->data = i;
    new_node->next = NULL;

    if (q->first != NULL)
        q->last = q->last->next = new_node;
    else
        q->first = q->last = new_node;
}

Item return_first(Queue q)
{
    assert(!is_empty(q));

    return q->first->data;
}

Item return_last(Queue q)
{
    assert(!is_empty(q));

    return q->last->data;
}
