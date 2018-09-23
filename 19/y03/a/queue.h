#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct queue_type *Queue;
typedef int Item; 

void make_empty(Queue q);
Queue create(void);
void destroy(Queue q);
bool is_empty(Queue q);
bool is_full(Queue q);
void insert_last(Queue q, Item i);
Item remove_first(Queue q);
Item return_first(Queue q);
Item return_last(Queue q);

#endif
