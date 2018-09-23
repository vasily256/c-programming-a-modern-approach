#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h" 

#define INIT_LEN 10

static int len = INIT_LEN;

struct queue_type {
    int empty_slot;
    int next_remove_item;
    int num_items;
    int max_items;
    Item *contents;
};

void make_empty(Queue q)
{
    q->empty_slot = q->next_remove_item = q->num_items = 0;
}

Queue create(void)
{
    Queue q = malloc(sizeof(struct queue_type));
    assert(q != NULL);

    q->contents = malloc(INIT_LEN * sizeof(Item));
    assert(q->contents != NULL);

    q->max_items = INIT_LEN;
    make_empty(q);
    return q;
}

void destroy(Queue q)
{
    free(q->contents);
    free(q);
}

bool is_empty(Queue q)
{
    return q->num_items == 0;
}

bool is_full(Queue q)
{
    return q->num_items == q->max_items;
}

static void expand(Queue q)
{
    Item *tmp_ptr = realloc(q->contents, (len += INIT_LEN) * sizeof(Item));
    assert(tmp_ptr != NULL);

    q->contents = tmp_ptr;
    q->max_items = len;
}

void insert_last(Queue q, Item i)
{
    if (is_full(q))
        expand(q);

    if (q->empty_slot == q->max_items)
        q->empty_slot = 0;

    q->contents[q->empty_slot++] = i; 
    q->num_items++;
}

Item remove_first(Queue q)
{
    assert(!is_empty(q));

    Item i = q->contents[q->next_remove_item++];
    q->num_items--;

    if (q->next_remove_item == q->max_items)
        q->next_remove_item = 0;

    return i;
} 

Item return_first(Queue q)
{
    assert(!is_empty(q));

    return q->contents[q->next_remove_item];
}

Item return_last(Queue q)
{
    assert(!is_empty(q));

    if (q->empty_slot == 0)
        return q->contents[q->max_items - 1];
    else
        return q->contents[q->empty_slot - 1];
}
