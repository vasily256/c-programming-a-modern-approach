#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
static void terminate(char *message);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, int i);
int pop(Stack s);
void make_empty(Stack s);

#endif
