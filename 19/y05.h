#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define LEN 10

struct Queue {
    int empty_slot;
    int next_remove_item;
    int num_items;
    int max_items;
    int contents[LEN];
};

void make_empty(Queue *q);
Queue *create(void);
void destroy(Queue *q);
bool is_empty(Queue *q);
bool is_full(Queue *q);
void insert_last(Queue *q, int i);
int remove_first(Queue *q);
int return_first(Queue *q);
int return_last(Queue *q);

#endif
